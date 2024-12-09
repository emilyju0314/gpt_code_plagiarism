void UKF::PredictSigmaPoints(double delta_t, const MatrixXd &Xsig_aug) {

  VectorXd x_aug = VectorXd(n_aug_);
  VectorXd x_k;
  VectorXd model;
  VectorXd noise;

  // helper variables for readability
  double psi, psi_d, v;
  double nu_a, nu_psi_dd;
  double cos_psi;
  double sin_psi;
  double c1, c2;
  const double c3 = delta_t * delta_t / 2;

  for( int i = 0;  i < n_sigma_; i++ ) {

    // extracting the augmented state vector
    x_aug = Xsig_aug.col(i);

    // this is just for even more readability
    x_k = x_aug.head(n_x_);

    // initializing the helper variables (or extracting state vector variables)
    v = x_aug(2);
    psi = x_aug(3);
    psi_d = x_aug(4);
    nu_a = x_aug(5);
    nu_psi_dd = x_aug(6);

    // precomputing trigonometrical values
    sin_psi = sin(psi);
    cos_psi = cos(psi);

    // the noise will be the same in either case
    noise = VectorXd(n_x_);
    noise <<  c3 * cos_psi * nu_a,
              c3 * sin_psi * nu_a,
              delta_t * nu_a,
              c3 * nu_psi_dd,
              delta_t * nu_psi_dd;

    // ...but not the model
    model = VectorXd(n_x_);

    if ( abs(psi_d) < 0.0001 ) {
      // handling the case where psi_d is near-zero
      model <<  v * cos_psi * delta_t,
                v * sin_psi * delta_t,
                0,
                0,
                0;
    } else {
      // 'normal' case
      c1 = v / psi_d;
      c2 = psi + psi_d * delta_t;

      model <<  c1 * (sin(c2) - sin_psi),
                c1 * (-cos(c2) + cos_psi),
                0,
                psi_d * delta_t,
                0;
    }

    Xsig_pred_.col(i) = x_k + model + noise;
  }
}