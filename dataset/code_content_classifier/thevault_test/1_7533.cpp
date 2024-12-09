void UKF::ProcessMeasurement(MeasurementPackage meas_package) {
  /**
  TODO:

  Complete this function! Make sure you switch between lidar and radar
  measurements.
  */

  /*************
  Initialization 
  **************/
  if (!is_initialized_) {
    // set the timestamp
    time_us_ = meas_package.timestamp_;
    // initialize x 
    x_ << 0, 0, 5.0, 0.5, 0.1;
    if (meas_package.sensor_type_ == MeasurementPackage::LASER) {
      x_(0) = meas_package.raw_measurements_(0);
      x_(1) = meas_package.raw_measurements_(1);  
    }
    else if (meas_package.sensor_type_ == MeasurementPackage::RADAR) {
      double ro = meas_package.raw_measurements_(0);
      double theta = meas_package.raw_measurements_(1);
      x_(0) = ro*cos(theta);
      x_(1) = ro*sin(theta);
    }

    // initialize P
    P_ << 0.01, 0, 0, 0, 0,
          0, 0.01, 0, 0, 0,
          0, 0, 0.01, 0, 0,
          0, 0, 0, 0.01, 0,
          0, 0, 0, 0, 0.01;

    // done initialization
    is_initialized_ = true;
    return;
  }

  /*
  Print Debug
  */
  //std::cout << "x:" << x_ << std::endl;
  //std::cout << "P:" << P_ << std::endl;
  //std::cout << "\n";

  /*************
  Prediction 
  **************/
  double delta_t = (meas_package.timestamp_ - time_us_) / 1000000.0;
  time_us_ = meas_package.timestamp_;
  //std::cout << "delta_t: " << delta_t << std::endl;
  Prediction(delta_t);

  /*************
  Update
  **************/
  if (meas_package.sensor_type_ == MeasurementPackage::LASER) {
    UpdateLidar(meas_package);
  }
  else if (meas_package.sensor_type_ == MeasurementPackage::RADAR) {
    UpdateRadar(meas_package);
  }
}