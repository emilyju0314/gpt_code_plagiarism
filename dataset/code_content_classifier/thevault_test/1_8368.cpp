void UKF::GenerateSigmaPoints(MatrixXd &Xsig_aug) {

  // augmented mean state
  VectorXd x_aug = VectorXd(n_aug_);
  x_aug.fill(0.0);
  x_aug.head(n_x_) = x_;

  // initializing augmented covariance matrix
  MatrixXd P_aug = MatrixXd(n_aug_, n_aug_);
  P_aug.fill(0.0);
  P_aug.topLeftCorner(n_x_, n_x_) = P_;
  P_aug(n_x_,   n_x_)   = std_a_ * std_a_;
  P_aug(n_x_+1, n_x_+1) = std_yawdd_ * std_yawdd_;

  // creating square root matrix
  const MatrixXd A = P_aug.llt().matrixL();

  // copying x_aug to the first column  
  Xsig_aug.col(0) = x_aug;

  // precomputing the commonly used matrix
  const MatrixXd A_helper = sqrt(n_aug_ + lambda_) * A;

  // performing column copying
  for( int i = 0; i < n_aug_; ++i ) {

    Xsig_aug.col(1+i) = x_aug + A_helper.col(i);
    Xsig_aug.col(1+i+n_aug_) = x_aug - A_helper.col(i);
  }
}