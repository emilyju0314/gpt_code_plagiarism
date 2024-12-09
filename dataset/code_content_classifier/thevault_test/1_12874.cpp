BOOST_AUTO_TEST_CASE(SimpleCVMSETest)
{
  // Using the first two points for training and remaining three for validation.
  // See the test MSETest for more explanation.
  arma::mat data("0 1 2 3 4");
  arma::rowvec responses("-1 0 1 3 5");

  double expectedMSE = (0 * 0 + 1 * 1 + 2 * 2) / 3.0;

  SimpleCV<LinearRegression, MSE> cv(0.6, data, responses);

  BOOST_REQUIRE_CLOSE(cv.Evaluate(), expectedMSE, 1e-5);

  arma::mat noiseData("-1 -2 -3 -4 -5");
  arma::rowvec noiseResponses("10 20 30 40 50");

  arma::mat allData = arma::join_rows(noiseData, data);
  arma::rowvec allResponces = arma::join_rows(noiseResponses, responses);

  arma::rowvec weights = arma::join_rows(arma::zeros(noiseData.n_cols).t(),
      arma::ones(data.n_cols).t());

  SimpleCV<LinearRegression, MSE> weightedCV(0.3, allData, allResponces,
      weights);

  BOOST_REQUIRE_CLOSE(weightedCV.Evaluate(), expectedMSE, 1e-5);

  arma::rowvec weights2 = arma::join_rows(arma::zeros(noiseData.n_cols - 1).t(),
      arma::ones(data.n_cols + 1).t());

  SimpleCV<LinearRegression, MSE> weightedCV2(0.3, allData, allResponces,
      weights2);

  BOOST_REQUIRE_GT(std::abs(weightedCV2.Evaluate() - expectedMSE), 1e-5);
}