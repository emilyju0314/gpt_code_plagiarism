void UKF::PredictLidarMeasurement(VectorXd &z_pred, MatrixXd &Zsig, MatrixXd &S) {

  // measurement dimension. lidar can measure px and py
  const int n_z = 2;

  // defining helper variables
  double px, py;
  VectorXd lidar_measurement = VectorXd(n_z);
  VectorXd z_diff = VectorXd(n_z);

  // transforming sigma points into measurement space
  for( int i = 0;  i < n_sigma_; i++ ) {

    // extracting values
    px = Xsig_pred_(0, i);
    py = Xsig_pred_(1, i);

    lidar_measurement << px, py;

    // filling Zsig and z_pred in the same loop
    Zsig.col(i) = lidar_measurement;
    z_pred += weights_(i) * lidar_measurement;
  }


  // calculating covariance matrix S
  for ( int i = 0;  i < n_sigma_; i++ ) {

    // calculating residual
    z_diff = Zsig.col(i) - z_pred;

    S += weights_(i) * z_diff * z_diff.transpose();
  }

  // measurement noise covariance matrix S
  MatrixXd R = MatrixXd(n_z, n_z);
  R <<  std_laspx_ * std_laspx_, 0,
        0, std_laspy_ * std_laspy_;

  // adding measurement noise to the covariance matrix
  S += R;
}