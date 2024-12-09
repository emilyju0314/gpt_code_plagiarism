void UKF::Prediction(double delta_t) {
  /**
  TODO:

  Complete this function! Estimate the object's location. Modify the state
  vector, x_. Predict sigma points, the state, and the state covariance matrix.
  */

  /*
  Generate augmented sigma points.
  */
  
  //create augmented mean vector
  VectorXd x_aug = VectorXd(7);
  //create augmented state covariance
  MatrixXd P_aug = MatrixXd(7, 7);
  //create sigma point matrix
  MatrixXd Xsig_aug = MatrixXd(n_aug_, 2 * n_aug_ + 1);
  //create augmented mean state
  x_aug.setZero();
  x_aug.head(n_x_) = x_;
  //create augmented covariance matrix
  P_aug.setZero();
  P_aug.topLeftCorner(n_x_, n_x_) = P_;
  MatrixXd Q = MatrixXd(2, 2);
  Q << std_a_*std_a_, 0,
       0, std_yawdd_*std_yawdd_;
  P_aug.bottomRightCorner(2, 2) = Q;
  //create square root matrix
  MatrixXd A = P_aug.llt().matrixL();
  //create augmented sigma points
  Xsig_aug.col(0) = x_aug;
  for (int i = 0; i < n_aug_; i++) {
      Xsig_aug.col(i+1) = x_aug + sqrt(lambda_ + n_aug_) * A.col(i);
      Xsig_aug.col(i+1+n_aug_) = x_aug - sqrt(lambda_ + n_aug_) * A.col(i);
  }

  //std::cout << "Xsig_aug:\n" << Xsig_aug << std::endl;

  /*
  Predict sigma points.
  */

  //create matrix with predicted sigma points as columns
  //MatrixXd Xsig_pred = MatrixXd(n_x_, 2 * n_aug_ + 1);
  for (int i = 0; i < 2*n_aug_+1; i++) {
      VectorXd current_x = Xsig_aug.col(i);
      // double p_x = current_x(0);
      // double p_y = current_x(1);
      double v = current_x(2);
      double phi = current_x(3);
      double phi_dot = current_x(4);
      double noise_a = current_x(5);
      double noise_phi = current_x(6);
      
      // a and b are two vectors in the prediction equation
      VectorXd a = VectorXd::Zero(n_x_);
      VectorXd b = VectorXd::Zero(n_x_);
      
      if (fabs(phi_dot) < 0.001) {
        a(0) = v*cos(phi)*delta_t;
        a(1) = v*sin(phi)*delta_t;
      }
      else {
        a(0) = (v/phi_dot) * (sin(phi+phi_dot*delta_t) - sin(phi));
        a(1) = (v/phi_dot) * (-cos(phi+phi_dot*delta_t) + cos(phi));
        a(3) = phi_dot*delta_t;
      }
      
      b(0) = 0.5*delta_t*delta_t * cos(phi) * noise_a;
      b(1) = 0.5*delta_t*delta_t * sin(phi) * noise_a; 
      b(2) = delta_t * noise_a;
      b(3) = 0.5*delta_t*delta_t * noise_phi;
      b(4) = delta_t * noise_phi;
      
      Xsig_pred_.col(i) = Xsig_aug.col(i).head(n_x_) + a + b;
  }
  //std::cout << "Xsig_pred:\n" << Xsig_pred_ << std::endl;

  /*
  Calculate mean state and variance 
  */
 
  //create vector for weights
  //VectorXd weights = VectorXd(2*n_aug_+1);
  int num_points = 2*n_aug_+1;
  //predict state mean
  x_.setZero();
  P_.setZero();
  for (int i = 0; i < num_points; i++) {
      x_ += weights_(i) * Xsig_pred_.col(i);
  }
  //predict state covariance matrix
  for (int i = 0; i < num_points; i++) {
      // state difference
      VectorXd x_diff = Xsig_pred_.col(i) - x_;
      //angle normalization
      while (x_diff(3)> M_PI) x_diff(3)-=2.*M_PI;
      while (x_diff(3)<-M_PI) x_diff(3)+=2.*M_PI;
      // if (x_diff(3) > 2*M_PI || x_diff(3) < -2*M_PI)
        // x_diff(3) = fmod(x_diff(3), 2*M_PI);       
      // std::cout << "x_diff: " << x_diff << std::endl;
      P_ += weights_(i) * x_diff * x_diff.transpose();
  }
//   std::cout << "x_pred:" << x_ << std::endl;
//   std::cout << "P_pred:" << P_ << std::endl;
//   std::cout << "\n";
}