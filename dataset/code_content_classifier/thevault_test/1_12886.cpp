BOOST_AUTO_TEST_CASE(CholeskySingularityTest)
{
  arma::mat X;
  arma::mat Y;

  data::Load("lars_dependent_x.csv", X);
  data::Load("lars_dependent_y.csv", Y);

  arma::rowvec y = Y.row(0);

  // Test for a couple values of lambda1.
  for (double lambda1 = 0.0; lambda1 < 1.0; lambda1 += 0.1)
  {
    LARS lars(true, lambda1, 0.0);
    arma::vec betaOpt;
    lars.Train(X, y, betaOpt);

    arma::vec errCorr = (X * X.t()) * betaOpt - X * y.t();

    LARSVerifyCorrectness(betaOpt, errCorr, lambda1);
  }
}