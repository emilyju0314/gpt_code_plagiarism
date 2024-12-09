void UKF::ProcessMeasurement(MeasurementPackage meas_package) {

  if (!is_initialized_) {
    // ...then initialize the filter (which shouldn't be allowed in case the measurement originates from
    // a sensor type that's currently disabled, but... well, whatever. :-( )
    Init(meas_package);
    return;
  }

  // do we have to consider this measurement package at all?
  if ( meas_package.sensor_type_ == MeasurementPackage::RADAR && !use_radar_ ||
       meas_package.sensor_type_ == MeasurementPackage::LASER && !use_laser_ ) {
    Log(" *** Skipping data package as the measurements from this sensor type will be ignored in this run.");
    return;
  }

  // computing the time elapsed between the current and previous measurements (in seconds)
  const double dt = (meas_package.timestamp_ - time_us_) / 1000000.0;
  time_us_ = meas_package.timestamp_;

  // prediction step
  Prediction(dt);

  // measurement update step
  if (meas_package.sensor_type_ == MeasurementPackage::RADAR && use_radar_) {
    UpdateRadar(meas_package);

  } else if (meas_package.sensor_type_ == MeasurementPackage::LASER && use_laser_) {
    UpdateLidar(meas_package);
  }
}