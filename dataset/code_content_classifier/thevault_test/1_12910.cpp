BOOST_AUTO_TEST_CASE(LARSTest)
{
  using namespace mlpack::regression;

  // Create a dataset.
  arma::mat X = arma::randn(75, 250);
  arma::vec beta = arma::randn(75, 1);
  arma::rowvec y = beta.t() * X;

  LARS lars(true, 0.1, 0.1);
  arma::vec betaOpt;
  lars.Train(X, y, betaOpt);

  // Now, serialize.
  LARS xmlLars(false, 0.5, 0.0), binaryLars(true, 1.0, 0.0),
      textLars(false, 0.1, 0.1);

  // Train textLars.
  arma::mat textX = arma::randn(25, 150);
  arma::vec textBeta = arma::randn(25, 1);
  arma::rowvec textY = textBeta.t() * textX;
  arma::vec textBetaOpt;
  textLars.Train(textX, textY, textBetaOpt);

  SerializeObjectAll(lars, xmlLars, binaryLars, textLars);

  // Now, check that predictions are the same.
  arma::rowvec pred, xmlPred, textPred, binaryPred;
  lars.Predict(X, pred);
  xmlLars.Predict(X, xmlPred);
  textLars.Predict(X, textPred);
  binaryLars.Predict(X, binaryPred);

  CheckMatrices(pred, xmlPred, textPred, binaryPred);
}