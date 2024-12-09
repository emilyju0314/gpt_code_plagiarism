void UKF::PredictRadarMeasurement(VectorXd &z_pred, MatrixXd &Zsig, MatrixXd &S) {

  // measurement dimension. radar can measure r, phi, and r_dot
  const int n_z = 3;

  // defining helper variables
  double px, py, v, psi, r, phi, r_d;
  VectorXd radar_measurement = VectorXd(n_z);
  VectorXd z_diff = VectorXd(n_z);

  // transforming sigma points into measurement space
  for( int i = 0;  i < n_sigma_; i++ ) {

    // extracting values
    px = Xsig_pred_(0, i);
    py = Xsig_pred_(1, i);
    v = Xsig_pred_(2, i);
    psi = Xsig_pred_(3, i);

    r = sqrt(px*px + py*py);
    phi = atan2(py, px);
    r_d = v * (px*cos(psi) + py*sin(psi)) / r;

    radar_measurement << r, phi, r_d;

    // filling Zsig and z_pred in the same loop
    Zsig.col(i) = radar_measurement;
    z_pred += weights_(i) * radar_measurement;
  }


  // calculating covariance matrix S
  for ( int i = 0;  i < n_sigma_; i++ ) {

    // calculating residual with angle normalization
    z_diff = Zsig.col(i) - z_pred;
    NormalizeAngle(z_diff(1));

    S += weights_(i) * z_diff * z_diff.transpose();
  }

  // measurement noise covariance matrix S
  MatrixXd R = MatrixXd(n_z, n_z);
  R <<  std_radr_ * std_radr_, 0, 0,
        0, std_radphi_ * std_radphi_, 0,
        0, 0, std_radrd_ * std_radrd_;

  // adding measurement noise to the covariance matrix
  S += R;
}