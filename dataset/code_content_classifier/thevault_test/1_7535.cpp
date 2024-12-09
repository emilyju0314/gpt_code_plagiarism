void UKF::UpdateLidar(MeasurementPackage meas_package) {
  /**
  TODO:

  Complete this function! Use lidar data to update the belief about the object's
  position. Modify the state vector, x_, and covariance, P_.

  You'll also need to calculate the lidar NIS.
  */
  //set measurement dimension, lidar can measure px and py.
  int n_z = 2;

  //create matrix for sigma points in measurement space
  MatrixXd Zsig = MatrixXd(n_z, 2 * n_aug_ + 1);

  //mean predicted measurement
  VectorXd z_pred = VectorXd(n_z);
  
  //measurement covariance matrix S
  MatrixXd S = MatrixXd(n_z,n_z);

  // transform sigma points into measurement space
  for (int i = 0; i < 2*n_aug_+1; i++) {
      Zsig.col(i)(0) = Xsig_pred_.col(i)(0);
      Zsig.col(i)(1) = Xsig_pred_.col(i)(1);
  }
  
  //calculate mean predicted measurement
  z_pred.setZero();
  for (int i = 0; i < 2*n_aug_+1; i++) {
      z_pred += weights_(i) * Zsig.col(i);
  }
  
  //calculate innovation covariance matrix S
  MatrixXd R = MatrixXd::Zero(2, 2);
  R(0,0) = std_laspx_*std_laspx_;
  R(1,1) = std_laspy_*std_laspy_;
  
  S.setZero();
  for (int i = 0; i < 2*n_aug_+1; i++) {
      VectorXd z_diff = Zsig.col(i) - z_pred;
      S += weights_(i) * z_diff * z_diff.transpose();
  } 
  S += R;

  /*****
  Update
  ******/

  //create matrix for cross correlation Tc
  MatrixXd Tc = MatrixXd(n_x_, n_z);
  //calculate cross correlation matrix
  Tc.setZero();
  for (int i = 0; i < 2 * n_aug_ + 1; i++) {
      Tc += weights_(i) * (Xsig_pred_.col(i) - x_) * (Zsig.col(i) - z_pred).transpose();
  }
  
  //calculate Kalman gain K;
  MatrixXd K = Tc * S.inverse();
  //create vector for incoming radar measurement
  VectorXd z = meas_package.raw_measurements_; 
  //update state mean and covariance matrix
  x_ = x_ + K * (z - z_pred);
  P_ = P_ - K*S*K.transpose();

  // compute the NIS
  // double epsilon = 0.0;
  double epsilon = (z - z_pred).transpose() * S.inverse() * (z - z_pred);
}