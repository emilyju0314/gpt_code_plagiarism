BOOST_AUTO_TEST_CASE(RetrainTest)
{
  arma::mat origX;
  arma::rowvec origY;
  GenerateProblem(origX, origY, 1000, 50);

  arma::mat newX;
  arma::rowvec newY;
  GenerateProblem(newX, newY, 750, 75);

  LARS lars(false, 0.1, 0.1);
  arma::vec betaOpt;
  lars.Train(origX, origY, betaOpt);

  // Now train on new data.
  lars.Train(newX, newY, betaOpt);

  arma::vec errCorr = (newX * trans(newX) + 0.1 *
        arma::eye(75, 75)) * betaOpt - newX * newY.t();

  LARSVerifyCorrectness(betaOpt, errCorr, 0.1);
}