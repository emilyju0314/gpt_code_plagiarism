void OrientationValues::Update() {
  //check whether magnetic calibration has been requested to be saved
  if( 1 == save_mag_cal_ ) {
    orientation_sensor_->sensor_interface_->InjectCommand("SVMC");
    save_mag_cal_ = 0;  // set flag back to zero so we don't repeat save
  }
  //check which type of parameter is requested, and pass it on
  switch (value_type_) {
    case (kCompassHeading):
      output = orientation_sensor_->sensor_interface_->GetHeadingRadians();
      break;
    case (kRoll):
      output = orientation_sensor_->sensor_interface_->GetRollRadians();
      break;
    case (kPitch):
      output = orientation_sensor_->sensor_interface_->GetPitchRadians();
      break;
    case (kAccelerationX):
      output = orientation_sensor_->sensor_interface_->GetAccelXMPerSS();
      break;
    case (kAccelerationY):
      output = orientation_sensor_->sensor_interface_->GetAccelYMPerSS();
      break;
    case (kAccelerationZ):
      output = orientation_sensor_->sensor_interface_->GetAccelZMPerSS();
      break;
    case (kRateOfTurn):
      output = orientation_sensor_->sensor_interface_->GetTurnRateRadPerS();
      break;
    case (kRateOfPitch):
      output = orientation_sensor_->sensor_interface_->GetPitchRateRadPerS();
      break;
    case (kRateOfRoll):
      output = orientation_sensor_->sensor_interface_->GetRollRateRadPerS();
      break;
    case (kTemperature):
      output = orientation_sensor_->sensor_interface_->GetTemperatureK();
      break;
    default:
      return; //skip the notify(), due to unrecognized value type
  }
  if (orientation_sensor_->sensor_interface_->IsDataValid()) {
    notify();  // only pass on the data if it is valid
  }
}