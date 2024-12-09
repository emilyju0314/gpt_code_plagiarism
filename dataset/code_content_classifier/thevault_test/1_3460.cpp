double timestep_size(std::uint64_t timestep)
{
  // locking

  std::lock_guard<hpx::lcos::local::mutex> l(grid.time_array.at(timestep).mtx);

  // if it has already been calculated, then just return the value
  if (grid.time_array.at(timestep).computed)
  {return grid.time_array.at(timestep).dt;}
  //  cout << (boost::format("calculating timestep, ts=%1% \n") % timestep) << flush;


  // if the current timestep is less than n_predict, then we manually
  // decide the timestep
  if (timestep < n_predict)
    {
      grid.time_array.at(timestep).computed = true;
      grid.time_array.at(timestep).dt = dx*0.033;// this should be fine unless
        // the initial conditions are changed
        if(timestep>0&&grid.time_array.at(timestep-1).computed)
            grid.time_array[timestep].physics_time =
            (grid.time_array.at(timestep-1).physics_time+grid.
                time_array.at(timestep).dt);
  //    time_array[timestep].dt = cfl_predict_factor*dt_cfl;
        else if(timestep==0)
        {
            grid.time_array.at(timestep).physics_time=grid.time_array.at(timestep).dt;
        }
      return grid.time_array.at(timestep).dt;
    }

  // send back the compute futures for the whole grid
  // n_predict timesteps previous to the one we want to decide
  // the timestep for
  //  cout << (boost::format("pushing back futures for ts calc, ts=%1% \n") % timestep)
  //  << flush;
  if(timestep>=n_predict)
  {
  for (std::uint64_t i=0;i<nx;i++)
      grid.time_array.at(timestep).fluid_future.push_back(async<compute_action>
          (here,timestep-n_predict,i));
  }

  double dt_cfl = 1000.0;

   wait_each(
      hpx::util::unwrapped([&](cell const& this_cell)
      {
      // look at all of the cells at a timestep, then pick the smallest
      // dt_cfl = cfl_factor*dx/(soundspeed+absolute_velocity)
      double abs_velocity = this_cell.mom/this_cell.rho;
      double pressure = get_pressure(this_cell);
      double soundspeed = sqrt(fluid_gamma*pressure/this_cell.rho);
      double dt_cfl_here = cfl_factor*dx/(soundspeed+abs_velocity);
      if (dt_cfl_here <=  0.0)
        {
          cout << (boost::format("error: CFL value can't be zero")) << flush;
          //error, quit everything
        }
      if (dt_cfl_here < dt_cfl)
        dt_cfl = dt_cfl_here;
     }),
     grid.time_array.at(timestep).fluid_future);

  // initialize dt_cfl to some arbitrary high value


  // wait for an array of futures
  /*wait_each(grid.time_array,
    hpx::util::unwrapped([&](cell const& this_cell)
    {
      // look at all of the cells at a timestep, then pick the smallest
      // dt_cfl = cfl_factor*dx/(soundspeed+absolute_velocity)
      double abs_velocity = this_cell.mom/this_cell.rho;
      double pressure = get_pressure(this_cell);
      double soundspeed = sqrt(fluid_gamma*pressure/this_cell.rho);
      double dt_cfl_here = cfl_factor*dx/(soundspeed+abs_velocity);
      if (dt_cfl_here <=  0.0)
        {
          cout << (boost::format("error: CFL value can't be zero")) << flush;
          //error, quit everything
        }
      if (dt_cfl_here < dt_cfl)
        dt_cfl = dt_cfl_here;
    }));
*/


  if(dt_cfl > 999.0)
    {
      cout << (boost::format("error: CFL value too high")) << flush;
      // error, quit everything
    }

  // we don't want to let the timestep increase too quickly, so
  // we only let it increase by 25% each timestep
  grid.time_array.at(timestep).computed = true;
  grid.time_array.at(timestep).dt = (std::min)(
                                     cfl_predict_factor*dt_cfl
                                     ,
                                     1.25*grid.time_array.at(timestep-1).dt);

  //  cout << (boost::format("timestep = %1%, dt = %2%\n")
  //  % timestep % time_array[timestep].dt) << flush;
  return grid.time_array[timestep].dt;
}