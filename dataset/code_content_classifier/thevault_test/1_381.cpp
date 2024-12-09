bool JerkMinimalTrajectory::valid_trajectory(){

  bool is_valid = true;
  double total_jerk=0, total_velocity=0, total_acceleration=0;
  for(int i=0; i<NUM_SIMULATOR_POINTS; i++){
    total_velocity = magnitude(this->get_velocity((i+1)*UPDATE_RATE, S_COORD), this->get_velocity((i+1)*UPDATE_RATE, D_COORD));
    total_acceleration = magnitude(this->get_acceleration((i+1)*UPDATE_RATE, S_COORD), this->get_acceleration((i+1)*UPDATE_RATE, D_COORD));
    total_jerk = magnitude(this->get_jerk((i+1)*UPDATE_RATE, S_COORD), this->get_jerk((i+1)*UPDATE_RATE, D_COORD));
    if(MAX_ACC*0.90 <= total_acceleration || MAX_SPEED_MPH*MPH_TO_MPS*0.95 <= total_velocity || MAX_JERK*0.95 <= total_jerk ){
      is_valid = false;
      // std::cout << " ACC: " << total_acceleration << ",  VEL: " << total_velocity << ", JERK: " << total_jerk <<  std::endl;
      break;
    }
  }

  return is_valid;
}