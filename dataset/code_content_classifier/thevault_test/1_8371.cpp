void UKF::UpdateLidar(MeasurementPackage meas_package) {

  // measurement dimension. lidar can measure px and py
  const int n_z = 2;

  VectorXd z_pred = VectorXd(n_z);              // predicted measurement
  MatrixXd Zsig = MatrixXd(n_z, n_sigma_);      // sigma points transformed to measurement space
  MatrixXd S = MatrixXd(n_z, n_z);              // measurement covariance matrix

  // initializing in/out variables
  Zsig.fill(0.0);
  z_pred.fill(0.0);
  S.fill(0.0);

  // 1: measurement prediction step
  PredictLidarMeasurement(z_pred, Zsig, S);

  // 2: update step
  UpdateState(meas_package, z_pred, Zsig, S);

  // +1: calculating NIS
  CalculateNIS(meas_package, z_pred, S);
}