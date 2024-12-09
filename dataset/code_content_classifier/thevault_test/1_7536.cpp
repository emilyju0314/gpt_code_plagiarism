void UKF::UpdateRadar(MeasurementPackage meas_package) {
  /**
  TODO:

  Complete this function! Use radar data to update the belief about the object's
  position. Modify the state vector, x_, and covariance, P_.

  You'll also need to calculate the radar NIS.
  */

  //set measurement dimension, radar can measure r, phi, and r_dot
  int n_z = 3;

  //create matrix for sigma points in measurement space
  MatrixXd Zsig = MatrixXd(n_z, 2 * n_aug_ + 1);

  //mean predicted measurement
  VectorXd z_pred = VectorXd(n_z);
  
  //measurement covariance matrix S
  MatrixXd S = MatrixXd(n_z,n_z);

  //transform sigma points into measurement space
  for (int i = 0; i < 2*n_aug_+1; i++) {
      float px = Xsig_pred_.col(i)(0); 
      float py = Xsig_pred_.col(i)(1); 
      float v = Xsig_pred_.col(i)(2); 
      float phi = Xsig_pred_.col(i)(3);
      
      Zsig.col(i)(0) = sqrt(px*px + py*py);
      Zsig.col(i)(1) = atan2(py, px);
      Zsig.col(i)(2) = (px*cos(phi)*v + py*sin(phi)*(v)) / sqrt(px*px + py*py);
  }
  
  //calculate mean predicted measurement
  z_pred.setZero();
  for (int i = 0; i < 2*n_aug_+1; i++) {
      z_pred += weights_(i) * Zsig.col(i);
  }
  
  //calculate innovation covariance matrix S
  MatrixXd R = MatrixXd::Zero(3, 3);
  R(0,0) = std_radr_*std_radr_;
  R(1,1) = std_radphi_*std_radphi_;
  R(2,2) = std_radrd_*std_radrd_;
  
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
  //std::cout << "cross correlation matrix: " << Tc << std::endl;
  
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