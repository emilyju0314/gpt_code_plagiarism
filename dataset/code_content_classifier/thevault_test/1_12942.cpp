BOOST_AUTO_TEST_CASE(LogisticRegressionSGDSimpleTest)
{
  // Very simple fake dataset.
  arma::mat data("1 2 3;"
                 "1 2 3");
  arma::Row<size_t> responses("1 1 0");

  // Create a logistic regression object using a custom SGD object with a much
  // smaller tolerance.
  ens::StandardSGD sgd(0.005, 1, 500000, 1e-10);
  LogisticRegression<> lr(data, responses, sgd, 0.001);

  // Test sigmoid function.
  arma::rowvec sigmoids = 1 / (1 + arma::exp(-lr.Parameters()[0]
      - lr.Parameters().tail_cols(lr.Parameters().n_elem - 1) * data));

  // Large 0.1% error tolerance is because the optimizer may terminate before
  // the predictions converge to 1.  SGD tolerance is larger because its default
  // convergence tolerance is larger.
  BOOST_REQUIRE_CLOSE(sigmoids[0], 1.0, 3.0);
  BOOST_REQUIRE_CLOSE(sigmoids[1], 1.0, 12.0);
  BOOST_REQUIRE_SMALL(sigmoids[2], 0.1);
}