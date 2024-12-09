BOOST_AUTO_TEST_CASE(BinaryClassificationMetricsTest)
{
  // Using the same data for training and testing.
  arma::mat data = arma::linspace<arma::rowvec>(1.0, 10.0, 10);

  // Labels that will be considered as "ground truth".
  arma::Row<size_t> labels("0 0 1 0 0  1 0 1 0 1");

  // Labels that make the data linearly separable. These labels will be
  // predicted in response to the data since we use them for training.
  arma::Row<size_t> predictedLabels("0 0 0 0 0  1 1 1 1 1");

  LogisticRegression<> lr(data, predictedLabels);

  BOOST_REQUIRE_CLOSE(Accuracy::Evaluate(lr, data, labels), 0.7, 1e-5);

  BOOST_REQUIRE_CLOSE(Precision<Binary>::Evaluate(lr, data, labels), 0.6, 1e-5);

  BOOST_REQUIRE_CLOSE(Recall<Binary>::Evaluate(lr, data, labels), 0.75, 1e-5);

  double f1 = 2 * 0.6 * 0.75 / (0.6 + 0.75);
  BOOST_REQUIRE_CLOSE(F1<Binary>::Evaluate(lr, data, labels), f1, 1e-5);
}