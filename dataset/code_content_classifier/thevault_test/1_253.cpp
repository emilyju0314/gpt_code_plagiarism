void AttitudeValues::Update() {
  //check whether magnetic calibration has been requested to be saved
  if( 1 == save_mag_cal_ ) {
    orientation_sensor_->sensor_interface_->InjectCommand("SVMC");
    save_mag_cal_ = 0;  // set flag back to zero so we don't repeat save
  }
  attitude_.is_data_valid =
      orientation_sensor_->sensor_interface_->IsDataValid();
  attitude_.yaw = orientation_sensor_->sensor_interface_->GetHeadingRadians();
  attitude_.roll =
      orientation_sensor_->sensor_interface_->GetRollRadians();
  attitude_.pitch =
      orientation_sensor_->sensor_interface_->GetPitchRadians();

  output = attitude_;
  notify();
}