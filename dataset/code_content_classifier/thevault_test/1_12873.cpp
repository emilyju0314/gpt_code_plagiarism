BOOST_AUTO_TEST_CASE(SimpleCVAccuracyTest)
{
  // Using the first half of data for training and the rest for validation.
  // The validation labels are 75% correct.
  arma::mat data =
    arma::mat("1 0; 2 0; 1 1; 2 1; 1 0; 2 0; 1 1; 2 1").t();
  arma::Row<size_t> labels("0 0 1 1 0 1 1 1");

  SimpleCV<LogisticRegression<>, Accuracy> cv(0.5, data, labels);

  BOOST_REQUIRE_CLOSE(cv.Evaluate(), 0.75, 1e-5);
}