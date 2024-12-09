void UKF::Init(MeasurementPackage meas_package) {

  // first measurement
  Log("[UKF] initializing...", false);

  // state vector elements. "assuming" a kind of hibernated object
  double px, py;
  double v = 0, yaw = 0, yaw_d = 0.1;

  if (meas_package.sensor_type_ == MeasurementPackage::RADAR) {

    // extracting values
    float ro = meas_package.raw_measurements_[0];
    yaw = meas_package.raw_measurements_[1];

    // Converting radar from polar to cartesian coordinates
    px = cos(yaw) * ro;
    py = sin(yaw) * ro;

  } else if (meas_package.sensor_type_ == MeasurementPackage::LASER) {

    // initializing the state with the given position and zero velocity
    px = meas_package.raw_measurements_[0];
    py = meas_package.raw_measurements_[1];
  }

  // state vector initialization
  x_ << px, py, v, yaw, yaw_d;

  // we don't pretend to be pretty sure about the world out there
  P_ << 0.8, 0, 0, 0, 0,
        0, 0.8, 0, 0, 0,
        0, 0, 0.8, 0, 0,
        0, 0, 0, 0.8, 0,
        0, 0, 0, 0, 0.8;

  // storing the timestamp, too
  time_us_ = meas_package.timestamp_;

  // initialization is done
  is_initialized_ = true;

  Log(" done.");
}