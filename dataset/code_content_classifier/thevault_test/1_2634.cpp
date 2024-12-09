EpStatus
Equipartition::equipartition_2(ep_real* bounds, ep_real* error)
{
  if (iverbose) {
    std::cout << "      Equipartitioning pair of intervals" << std::flush;
  }
  if (!errors_up_to_date) {
    calc_error_all(2, bounds, error);
    errors_up_to_date = true;
  }

  ep_real bound_left = bounds[0], bound_right = bounds[2];
  ep_real ediff_left, ediff_right;
  ep_real frac_error = 0.5*std::fabs(error[1]-error[0])/(error[0]+error[1]);

  ep_real local_tolerance = partition_tolerance;

  ep_real frac_error_orig = frac_error;
  ep_real newbounds[3] = {bounds[0], bounds[1], bounds[2]};
  ep_real newerror[2]  = {error[0], error[1]};

  int iterations_remaining = partition_max_iterations;

  if (error[0] > error[1]) {
    // Found an upper (right) limit on the middle bound; now find a
    // lower (left) limit
    bound_right = bounds[1];
    ediff_right = error[1]-error[0];  
    while (iterations_remaining) { // && frac_error > local_tolerance) {
      newbounds[1] = (-ediff_right*newbounds[0] + (newerror[0]+ediff_right)*newbounds[1])
	/ newerror[0];
      calc_error_all(2, newbounds, newerror);

      if (newerror[0] < newerror[1]) {
	// Found left limit
	bound_left = newbounds[1];
	ediff_left = newerror[1]-newerror[0];
	break;
      }
      ediff_right = newerror[1]-newerror[0];
      --iterations_remaining;
    }
  }
  else {
    // Found a lower (left) limit on the middle bound; now find an
    // upper (right) limit
    bound_left = bounds[1];
    ediff_left = error[1]-error[0];
    while (iterations_remaining) { // && frac_error > local_tolerance) {
      newbounds[1] = (ediff_left*newbounds[2] + (newerror[1]-ediff_left)*newbounds[1])
	/ newerror[1];
      calc_error_all(2, newbounds, newerror);

      if (newerror[0] > newerror[1]) {
	// Found right limit
	bound_right = newbounds[1];
	ediff_right = newerror[1]-newerror[0];
	break;
      }
      ediff_left = newerror[1]-newerror[0];
      --iterations_remaining;
    }
  }

  bool no_progress = false;
  ep_real prev_frac_error = frac_error;

  // We have bounds on both sides
  while (iterations_remaining) {
    // Remember ediff_right is negative
    if (no_progress) {
      newbounds[1] = 0.5 * (bound_right + bound_left);
    }
    else {
      newbounds[1] = (ediff_left*bound_right - ediff_right*bound_left) / (ediff_left-ediff_right);
    }
    calc_error_all(2, newbounds, newerror);

    ep_real ediff = newerror[1]-newerror[0];
    frac_error = 0.5*std::fabs(ediff)/(newerror[0]+newerror[1]);
    if (frac_error < local_tolerance && frac_error < frac_error_orig) {
      // Converged
      bounds[1] = newbounds[1];
      error[0] = newerror[0];
      error[1] = newerror[1];
      if (iverbose) {
	std::cout << " " << ep_status_string(EP_SUCCESS) << std::endl;
      }
      errors_up_to_date = true;
      return EP_SUCCESS;
    }
    else if (frac_error == prev_frac_error) {
      if (no_progress) {
	break;
      }
      else {
	no_progress = true;
      }
    }
    if (ediff < 0) {
      ediff_right = ediff;
      bound_right = newbounds[1];
    }
    else {
      ediff_left = ediff;
      bound_left = newbounds[1];
    }
    prev_frac_error = frac_error;
    --iterations_remaining;
  }

  EpStatus istatus = EP_SUCCESS;

  // Bounds not found; did we reduce the error difference?
  if (frac_error < frac_error_orig) {
    // Yes: save results
    bounds[1] = newbounds[1];
    error[0] = newerror[0];
    error[1] = newerror[1];
    if (iverbose) {
      std::cout << " " << frac_error_orig << "=>" << frac_error << std::flush;
    }
    errors_up_to_date = true;

    if (bound_right-bound_left < resolution) {
      istatus = EP_RESOLUTION_LIMIT_REACHED;
    }
    else if (!iterations_remaining) {
      istatus = EP_MAX_ITERATIONS_REACHED;
    }
  }
  else {
    istatus = EP_NO_PROGRESS;
  }

  if (iverbose) {
    std::cout << " " << ep_status_string(istatus) << std::endl;
  }
  return istatus;
}