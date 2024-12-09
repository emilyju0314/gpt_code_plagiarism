void UKF::UpdateState(const MeasurementPackage &measurement, const VectorXd &z_pred, const MatrixXd &Zsig, const MatrixXd &S) {

  const bool is_radar_measurement = measurement.sensor_type_ == MeasurementPackage::RADAR;
  const int n_z = is_radar_measurement ? 3 : 2;

  // create matrix for cross correlation Tc
  MatrixXd Tc = MatrixXd(n_x_, n_z);
  Tc.fill(0.0);

  // common helper variables
  VectorXd x_diff;
  VectorXd z_diff;

  // calculating cross correlation matrix
  for( int i = 0;  i < n_sigma_; i++ ) {

    // state difference (with angle normalization for radar measurements)
    x_diff = Xsig_pred_.col(i) - x_;
    if ( is_radar_measurement ) {
      NormalizeAngle(x_diff(3));
    }

    // residual (with angle normalization for radar measurements)
    z_diff = Zsig.col(i) - z_pred;
    if ( is_radar_measurement ) {
      NormalizeAngle(z_diff(1));
    }

    Tc += weights_(i) * x_diff * z_diff.transpose();
  }

  // calculating Kalman gain
  MatrixXd K = Tc * S.inverse();

  // residual (with angle normalization for radar measurements)
  z_diff = measurement.raw_measurements_ - z_pred;
  if ( is_radar_measurement ) {
    NormalizeAngle(z_diff(1));
  }

  // updating state mean and covariance matrix
  x_ += K * z_diff;
  P_ += -K * S * K.transpose();
}