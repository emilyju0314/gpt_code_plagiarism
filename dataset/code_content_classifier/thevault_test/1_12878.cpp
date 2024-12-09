BOOST_AUTO_TEST_CASE(KFoldCVWithWeightedLRTest)
{
  // Each fold will be filled with this dataset.
  arma::mat data("1 2 3 4");
  arma::rowvec responses("1 2 30 40");
  arma::rowvec weights("1 1 0 0");

  KFoldCV<LinearRegression, MSE> cv(2, arma::join_rows(data, data),
      arma::join_rows(responses, responses), arma::join_rows(weights, weights),
      false);
  cv.Evaluate();

  arma::mat testData("3 4");
  arma::rowvec testResponses("3 4");

  double mse = MSE::Evaluate(cv.Model(), testData, testResponses);

  BOOST_REQUIRE_CLOSE(1.0 - mse, 1.0, 1e-5);
}