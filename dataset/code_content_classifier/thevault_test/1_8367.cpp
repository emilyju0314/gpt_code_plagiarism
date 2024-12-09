void UKF::Prediction(double delta_t) {

  // defining matrix for holding the augmented sigma points
  MatrixXd Xsig_aug = MatrixXd(n_aug_, n_sigma_);
  Xsig_aug.fill(0.0);

  // 1: generate sigma points
  GenerateSigmaPoints(Xsig_aug);

  // 2: predict sigma points
  PredictSigmaPoints(delta_t, Xsig_aug);

  // 3: predict mean and covariance
  PredictMeanAndCovariance();
}