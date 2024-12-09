void UKF::PredictMeanAndCovariance() {

  // helper variable
  VectorXd x_diff = VectorXd(n_x_);

  // initializing
  P_.fill(0.0);

  // predicting state mean
  x_.fill(0.0);
  for( int i = 0;  i < n_sigma_; i++ ) {
    x_ += weights_(i) * Xsig_pred_.col(i);
  }

  // predict state covariance matrix
  for ( int i = 0;  i < n_sigma_; i++ ) {

    // state difference with normalized angle
    x_diff = Xsig_pred_.col(i) - x_;
    NormalizeAngle(x_diff(3));

    P_ += weights_(i) * x_diff * x_diff.transpose();
  }
}