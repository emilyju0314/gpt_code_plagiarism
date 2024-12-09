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
  //std_a_ = 1.18;  

  //std_a_ = 2;//p=50/0.4256//0.4391...p=20//0.4099//0.4380//
  //std_a_ = 2.4;//p=20//0.4022,0.1029//0.4297
  //std_a_ = 2.2;//p=20//0.4001,0.1006//0.4292
  //std_a_ = 2.15;//p=20//0.3988,0.1004//0.4282
  //std_a_ = 2.08;//p=20//0.3973,0.1002//0.4272
  //std_a_ = 2.02;//p=20//0.3962,0.1001//0.4265

  //std_a_ = 1.95;//p=24//0.3962,0.1001//0.4265

  //Tuned Value- Amazing Results
  std_a_ = 0.7;//p=24//0.3962,0.1001//0.4265
  
  // Process nose standard deviation yaw acceleration in rad/s^2
  //std_yawdd_ = 0.5;

  //std_yawdd_ = 0.3;//0.4256//0.4391.p=20//0.4099//0.4380//
  //std_yawdd_ = 0.6;//p=20//0.4022,0.1029//0.4297
  //std_yawdd_ = 0.8;//p=20//0.4001,0.1006//0.4292
  //std_yawdd_ = 0.75;//p=20//0.3988,0.1004//0.4282
  //std_yawdd_ = 0.70;//p=20//0.3973,0.1002//0.4272
  //std_yawdd_ = 0.65;//p=20//0.3962,0.1001//0.4265

  //Tuned Value - Amazing Results
  std_yawdd_ = 0.65;//p=20//0.3962,0.1001//0.4265
  
  
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
  
  /**
  TODO:

  Complete the initialization. See ukf.h for other member properties.

  Hint: one or more values initialized above might be wildly off...
  */
  is_initialized_=false;

  n_x_=5;

  n_aug_=7;

  lambda_=3-n_x_;

  Xsig_pred_ = MatrixXd(n_x_, 2 * n_aug_ + 1);

  time_us_=0;

  weights_=VectorXd(2*n_aug_ +1);

  NIS_Lidar_=0;

  NIS_radar_=0;

}