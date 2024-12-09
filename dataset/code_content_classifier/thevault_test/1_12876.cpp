BOOST_AUTO_TEST_CASE(KFoldCVMSETest)
{
  // Defining dataset with two sets of responses for the same two data points.
  arma::mat data("0 1  0 1");
  arma::rowvec responses("0 1  1 3");

  // 2-fold cross-validation, no shuffling.
  KFoldCV<LinearRegression, MSE> cv(2, data, responses, false);

  // In each of two validation tests the MSE value should be the same.
  double expectedMSE =
      double((1 - 0) * (1 - 0) + (3 - 1) * (3 - 1)) / 2 * 2 / 2;

  BOOST_REQUIRE_CLOSE(cv.Evaluate(), expectedMSE, 1e-5);

  // Assert we can access a trained model without the exception of
  // uninitialization.
  cv.Model();
}