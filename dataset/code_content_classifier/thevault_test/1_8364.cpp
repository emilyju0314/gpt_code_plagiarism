UKF::UKF() {

  // if this is false, laser measurements will be ignored (except during init)
  use_laser_ = true;

  // if this is false, radar measurements will be ignored (except during init)
  use_radar_ = true;

  // initial state vector
  x_ = VectorXd(5);

  // initial covariance matrix
  P_ = MatrixXd(5, 5);

  // Process noise standard deviation longitudinal acceleration in m/s^2
  std_a_ = 2.1;

  // Process noise standard deviation yaw acceleration in rad/s^2
  std_yawdd_ = 0.275;
  
  //DO NOT MODIFY measurement noise values below these are provided by the sensor manufacturer.
  // Laser measurement noise standard deviation position1 in m
  std_laspx_ = 0.15;

  // Laser measurement noise standard deviation position2 in m
  std_laspy_ = 0.15;

  // Radar measurement noise standard deviation radius in m
  std_radr_ = 0.3;

  // Radar measurement noise standard deviation angle in rad
  std_radphi_ = 0.03;

  // Radar measurement noise standard deviation radius change in m/s
  std_radrd_ = 0.3;
  //DO NOT MODIFY measurement noise values above these are provided by the sensor manufacturer.

  /* Completing the initialization. */
  is_initialized_ = false;
  time_us_ = 0;

  // number of things
  n_x_ = 5;
  n_aug_ = n_x_ + 2;
  lambda_ = 3 - n_aug_;
  n_sigma_ = 2 * n_aug_ + 1;

  // initializing (helper) vectors and matrices
  Xsig_pred_ = MatrixXd(n_x_, n_sigma_);
  Xsig_pred_.fill(0.0);

  x_.fill(0.0);
  P_.fill(0.0);

  // initializing weights
  weights_ = VectorXd(n_sigma_);
  weights_.fill(0.0);

  const double w_0 = lambda_ / (lambda_ + n_aug_);
  const double w_i = 0.5 / (lambda_ + n_aug_);

  weights_(0) = w_0;
  for ( int i = 1; i < n_sigma_; i++) {
    weights_(i) = w_i;
  }

  // controlling debug mode
  debug_mode_ = false;
}