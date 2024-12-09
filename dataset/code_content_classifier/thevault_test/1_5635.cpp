void UKF::Prediction(double delta_t) {
  /**
  TODO:

  Complete this function! Estimate the object's location. Modify the state
  vector, x_. Predict sigma points, the state, and the state covariance matrix.
  */
 MatrixXd Xsig=MatrixXd(n_x_, 2*n_x_+1);
 lambda_ = 3 - n_x_;

 MatrixXd A=P_.llt().matrixL();

 Xsig.col(0)=x_;

 for (int i=0; i<n_x_; i++){
   Xsig.col(i+1)=x_ + sqrt(lambda_+n_x_)*A.col(i);
   Xsig.col(i+1+n_x_)= x_ - sqrt(lambda_+n_x_)*A.col(i);

 }

 //Augementing the Sigma Points

 VectorXd X_aug= VectorXd(n_aug_);

 X_aug.head(5)=x_;
 X_aug(5)=0;
 X_aug(6)=0;

 //Augemented Covariance Matrix

 MatrixXd P_aug = MatrixXd(n_aug_, n_aug_);

 P_aug.fill(0.0);

 P_aug.topLeftCorner(5,5)=P_;
 P_aug(5,5) = std_a_*std_a_;
 P_aug(6,6) = std_yawdd_*std_yawdd_;

 //Square root Covariance Matrix

 MatrixXd L=P_aug.llt().matrixL();

 MatrixXd Xsig_aug=MatrixXd(n_aug_, 2*n_aug_ +1);

 Xsig_aug.col(0)= X_aug;

 lambda_=3-n_aug_;

 for (int i=0; i<n_aug_; i++){
   Xsig_aug.col(i+1)=X_aug + sqrt(lambda_+n_aug_)* L.col(i);
   Xsig_aug.col(i+1+n_aug_)= X_aug - sqrt(lambda_+n_aug_) *L.col(i);

 }


  /*****************************************************************************
  *  Predict Sigma Points
  ****************************************************************************/
//predict sigma points

for(int i=0; i<2*n_aug_+1; i++){

  double px=Xsig_aug(0,i);
  double py=Xsig_aug(1,i);
  double v=Xsig_aug(2,i);
  double yaw=Xsig_aug(3,i);
  double yawd=Xsig_aug(4,i);
  double nu_a=Xsig_aug(5,i);
  double nu_yawdd=Xsig_aug(6,i);

 //predicted state values
  double px_p, py_p;

    //avoid division by zero
  if (fabs(yawd) > 0.001) {
        px_p = px + v/yawd * ( sin (yaw + yawd*delta_t) - sin(yaw));
        py_p = py + v/yawd * ( cos(yaw) - cos(yaw+yawd*delta_t) );
  }
  else {
        px_p = px + v*delta_t*cos(yaw);
        py_p = py + v*delta_t*sin(yaw);
  }

  double v_p = v;
  double yaw_p = yaw + yawd*delta_t;
  double yawd_p = yawd;

    //add noise
  px_p = px_p + 0.5*nu_a*delta_t*delta_t * cos(yaw);
  py_p = py_p + 0.5*nu_a*delta_t*delta_t * sin(yaw);
  v_p = v_p + nu_a*delta_t;

  yaw_p = yaw_p + 0.5*nu_yawdd*delta_t*delta_t;
  yawd_p = yawd_p + nu_yawdd*delta_t;

    //write predicted sigma point into right column
  Xsig_pred_(0,i) = px_p;
  Xsig_pred_(1,i) = py_p;
  Xsig_pred_(2,i) = v_p;
  Xsig_pred_(3,i) = yaw_p;
  Xsig_pred_(4,i) = yawd_p;
}

//Mean and Covariance Prediction

//Weights Initializtion

double weights = lambda_/(lambda_+n_aug_);
weights_(0)=weights;

for(int i=1; i<2*n_aug_+1; i++){
  double weight_i=0.5/(lambda_+n_aug_);
  weights_(i)= weight_i;
}

//VectorXd x=VectorXd(n_x_);
x_.fill(0.0);

//MatrixXd P=MatrixXd(n_x_,n_x_);


for(int i=0; i<2*n_aug_ +1; i++){
  x_=x_+ (weights_(i)*Xsig_pred_.col(i));
} 

VectorXd x_diff=VectorXd(n_x_);
P_.fill(0.0);
for (int i = 0; i < 2 * n_aug_ + 1; i++) {  //iterate over sigma points

    // state difference
  x_diff = Xsig_pred_.col(i) - x_;
  //angle normalization
  if(x_diff(3) < -M_PI){
    x_diff(3) += 2 * M_PI;
  }else if (x_diff(3) > M_PI){
    x_diff(3) -= 2 * M_PI;
  }
    P_ = P_ + weights_(i) * x_diff * x_diff.transpose();
}
}