void UKF::UpdateLidar(MeasurementPackage meas_package) {

  VectorXd z=meas_package.raw_measurements_;

  int n_z=2;

  MatrixXd Zsig=MatrixXd(n_z,((2*n_aug_)+1));

  for(int i=0; i<2*n_aug_ +1; i++){
    double p_x=Xsig_pred_(0,i);
    double p_y=Xsig_pred_(1,i);


    Zsig(0,i)=p_x;
    Zsig(1,i)=p_y;
  }

  //Measurement Precdiction: Mean and Covariance

  VectorXd z_pred= VectorXd(n_z);

  z_pred.fill(0.0);

  for (int i=0; i<2*n_aug_ +1; i++){
    z_pred=z_pred+ (weights_(i)*Zsig.col(i));
  }

  MatrixXd S= MatrixXd(n_z,n_z);
  S.fill(0.0);

  VectorXd z_diff= VectorXd(n_z);
  for(int i=0; i<2 * n_aug_ +1; i++){

    z_diff = Zsig.col(i)-z_pred;

    S=S+ weights_(i) *z_diff * z_diff.transpose();
  }

  MatrixXd R= MatrixXd(n_z,n_z);

  R<<std_laspx_*std_laspx_,0,
     0,std_laspy_*std_laspy_;

  S=S+R;

  //Measurement Update

  MatrixXd Tc= MatrixXd(n_x_, n_z);

  Tc.fill(0.0);
  VectorXd x_diff= VectorXd(n_x_);

  for(unsigned int i=0; i<2 * n_aug_ + 1; i++){
    x_diff=Xsig_pred_.col(i)- x_;
    z_diff=Zsig.col(i)- z_pred;

    Tc = Tc + weights_(i) * x_diff * z_diff.transpose();
  }
  MatrixXd K = Tc * S.inverse();

  //residual
  z_diff = z - z_pred;

  //calculate NIS
   NIS_Lidar_= z_diff.transpose() * S.inverse() * z_diff;

  //update mean and covariance matrix
  x_ = x_ + K * z_diff;
  P_ = P_ - K*S*K.transpose();
  /**
  TODO:

  Complete this function! Use lidar data to update the belief about the object's
  position. Modify the state vector, x_, and covariance, P_.

  You'll also need to calculate the lidar NIS.
  */
}