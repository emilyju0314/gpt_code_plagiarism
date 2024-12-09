void UKF::Prediction(double delta_t) {
  /**
  TODO:

  Complete this function! Estimate the object's location. Modify the state
  vector, x_. Predict sigma points, the state, and the state covariance matrix.
  */

  //Step 1: Generatae Sigma points.
  VectorXd x_aug = VectorXd(n_aug_);
  x_aug.head(5) = x_;
  x_aug(5) = 0;
  x_aug(6) = 0;

  //augmentted state covaariancce
  MatrixXd P_aug = MatrixXd(n_aug_, n_aug_);
  P_aug.fill(0.0);
  P_aug.topLeftCorner(n_x_, n_x_) = P_;
  P_aug(5, 5) = std_a_ * std_a_;
  P_aug(6, 6) = std_yawdd_ * std_yawdd_;

  int n = x_aug.size();

  MatrixXd Xsig_aug_ = MatrixXd(n, n_sig_);
  MatrixXd SqrtP = P_aug.llt().matrixL();
  Xsig_aug_.col(0) = x_aug;

  double lambda_plue_n_x_sqrt = sqrt(lambda_ + n);

  //set remaning sigma points
  for (int i = 0; i < n; i++) {
    Xsig_aug_.col(i + 1) = x_aug + lambda_plue_n_x_sqrt * SqrtP.col(i);
    Xsig_aug_.col(i + 1 + n) = x_aug - lambda_plue_n_x_sqrt * SqrtP.col(i);
  }

  //Step 2: Predict Sigma Points.
  Xsig_pred_ = MatrixXd(n_x_, n_sig_);

  for (int i = 0; i < n_sig_; i++)
  {
    double p_x = Xsig_aug_(0, i);
    double p_y = Xsig_aug_(1, i);
    double v = Xsig_aug_(2, i);
    double yaw = Xsig_aug_(3, i);
    double yawd = Xsig_aug_(4, i);
    double nu_a = Xsig_aug_(5, i);
    double nu_yawdd = Xsig_aug_(6, i);

    //Predicted state values
    double px_p, py_p;

    //Check for division by zero
    if (fabs(yawd) > 0.001) {
      px_p = p_x + v / yawd * (sin(yaw + yawd * delta_t) - sin(yaw));
      py_p = p_y + v / yawd * (cos(yaw) - cos(yaw + yawd * delta_t));
    }
    else {
      px_p = p_x + v * delta_t*cos(yaw);
      py_p = p_y + v * delta_t*sin(yaw);
    }

    double v_p = v;
    double yaw_p = yaw + yawd * delta_t;
    double yawd_p = yawd;

    px_p = px_p + 0.5*nu_a*delta_t*delta_t * cos(yaw);
    py_p = py_p + 0.5*nu_a*delta_t*delta_t * sin(yaw);
    v_p = v_p + nu_a * delta_t;

    yaw_p = yaw_p + 0.5*nu_yawdd*delta_t*delta_t;
    yawd_p = yawd_p + nu_yawdd * delta_t;

    //Predicted sigma points
    Xsig_pred_(0, i) = px_p;
    Xsig_pred_(1, i) = py_p;
    Xsig_pred_(2, i) = v_p;
    Xsig_pred_(3, i) = yaw_p;
    Xsig_pred_(4, i) = yawd_p;
  }

  //Step 3: Predict Mean and Covariance
  //Predicted state mean
  x_ = Xsig_pred_ * weights_;

  //Predicted state covariance matrix
  P_.fill(0.0);

  //iterate over sigma points
  for (int i = 0; i < n_sig_; i++) {

    //State difference
    VectorXd x_diff = Xsig_pred_.col(i) - x_;

    //Angle normalization
    while (x_diff(3) > M_PI) x_diff(3) -= 2.*M_PI;
    while (x_diff(3) < -M_PI) x_diff(3) += 2.*M_PI;

    P_ = P_ + weights_(i) * x_diff * x_diff.transpose();
  }
}