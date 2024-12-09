void UKF::UpdateRadar(MeasurementPackage meas_package) {

  VectorXd z=meas_package.raw_measurements_;

  int n_z=3 ;

  MatrixXd Zsig=MatrixXd(n_z,2*n_aug_+1);

  for(int i=0; i<2*n_aug_ +1; i++){
    double p_x=Xsig_pred_(0,i);
    double p_y=Xsig_pred_(1,i);

    double v_radar=Xsig_pred_(2,i);

    double yaw_radar=Xsig_pred_(3,i);

    double vx= v_radar*cos(yaw_radar);
    double vy= v_radar*sin(yaw_radar);

    Zsig(0,i)=sqrt(p_x*p_x + p_y*p_y);
    Zsig(1,i)=atan2(p_y,p_x);
    Zsig(2,i)=(p_x*vx + p_y*vy) / sqrt(p_x*p_x + p_y*p_y);
  }

  //Measurement Precdiction: Mean and Covariance

  VectorXd z_pred= VectorXd(n_z);

  z_pred.fill(0.0);

  for (unsigned int i=0; i<2*n_aug_ +1; i++){
    z_pred=z_pred+ weights_(i)*Zsig.col(i);
  }

  MatrixXd S= MatrixXd(n_z,n_z);
  S.fill(0.0);

  VectorXd z_diff= VectorXd(n_z);

  for(int i=0; i<2 * n_aug_ +1; i++){

    z_diff = Zsig.col(i)-z_pred;

     //angle normalization

    if(z_diff(1) < -M_PI){
      z_diff(1) += 2 * M_PI;
    }
    else if (z_diff(1) > M_PI){
    z_diff(1) -= 2 * M_PI;
    }

    S=S+ weights_(i) *z_diff * z_diff.transpose();
  }

  MatrixXd R= MatrixXd(n_z,n_z);

  R<<std_radr_*std_radr_,0,0,
     0,std_radphi_*std_radphi_,0,
     0,0,std_radrd_*std_radrd_;

  S=S+R;

  //Measurement Update

  MatrixXd Tc= MatrixXd(n_x_, n_z);

  Tc.fill(0.0);

  VectorXd x_diff= VectorXd(n_x_);

  for(unsigned int i=0; i<2*n_aug_+1; i++){
    x_diff=Xsig_pred_.col(i)- x_;
    z_diff=Zsig.col(i)- z_pred;

     //residual
   z_diff = z - z_pred;

   //angle normalization
   if(z_diff(1) < -M_PI){
      z_diff(1) += 2 * M_PI;
    }
    else if (z_diff(1) > M_PI){
    z_diff(1) -= 2 * M_PI;
    }

     //residual

   //angle normalization
   if(x_diff(3) < -M_PI){
      x_diff(3) += 2 * M_PI;
    }
    else if (x_diff(3) > M_PI){
    x_diff(3) -= 2 * M_PI;
    }

    Tc = Tc + weights_(i) * x_diff * z_diff.transpose();
  }
  MatrixXd K = Tc * S.inverse();

  //residual
   z_diff = z - z_pred;

   //angle normalization
   if(z_diff(1) < -M_PI){
      z_diff(1) += 2 * M_PI;
    }
    else if (z_diff(1) > M_PI){
    z_diff(1) -= 2 * M_PI;
    }
  

  //calculate NIS
   NIS_radar_= z_diff.transpose() * S.inverse() * z_diff;

  //update mean and covariance matrix
  x_ = x_ + K * z_diff;
  P_ = P_ - K*S*K.transpose();
  /**
  TODO:

  Complete this function! Use radar data to update the belief about the object's
  position. Modify the state vector, x_, and covariance, P_.

  You'll also need to calculate the radar NIS.
  */

}