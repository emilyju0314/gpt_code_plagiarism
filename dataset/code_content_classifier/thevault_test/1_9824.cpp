void UKF::Prediction(double delta_t) {
  /**
  TODO:

  Complete this function! Estimate the object's location. Modify the state
  vector, x_. Predict sigma points, the state, and the state covariance matrix.
  */

  MatrixXd Xsig_aug = MatrixXd(n_aug_, 2 * n_aug_ + 1);
  AugmentedSigmaPoints(&Xsig_aug);

  for (int i = 0; i < 2 * n_aug_ + 1; i++) {
      Xsig_pred_.col(i) = Xsig_aug.col(i).head(5);
      
      float v = Xsig_aug(2, i);
      float psi = Xsig_aug(3, i);
      float psi_dot = Xsig_aug(4, i);
      float v_a = Xsig_aug(5, i);
      float v_psi_dotdot = Xsig_aug(6, i);
      
      Xsig_pred_(3, i) += psi_dot * delta_t;

      if (Xsig_aug(4, i) != 0) {
          Xsig_pred_(0, i) += (v / psi_dot) * (sin(psi + psi_dot * delta_t) - sin(psi));
          Xsig_pred_(1, i) += (v / psi_dot) * (-cos(psi + psi_dot * delta_t) + cos(psi));
      }
      else {
          Xsig_pred_(0, i) += v * cos(psi) * delta_t;
          Xsig_pred_(1, i) += v * sin(psi) * delta_t;
      }
      
      Xsig_pred_(0, i) += 0.5 * delta_t * delta_t * cos(psi) * v_a;
      Xsig_pred_(1, i) += 0.5 * delta_t * delta_t * sin(psi) * v_a;
      Xsig_pred_(2, i) += delta_t * v_a;
      Xsig_pred_(3, i) += 0.5 * delta_t * delta_t * v_psi_dotdot;
      Xsig_pred_(4, i) += delta_t * v_psi_dotdot;
  }
    
  //set weights
  
  weights_.fill(0.5 / (lambda_ + n_aug_));
  weights_(0) = lambda_ / (lambda_ + n_aug_);
  
  //predict state mean
  
  x_ = Xsig_pred_ * weights_;
  
  //predict state covariance matrix
  VectorXd ones = VectorXd(2 * n_aug_ + 1);
  ones.fill(1);
  
  P_ = (Xsig_pred_ - x_ * ones.transpose()) * 
    (weights_.asDiagonal()) * 
    (Xsig_pred_ - x_ * ones.transpose()).transpose();
}