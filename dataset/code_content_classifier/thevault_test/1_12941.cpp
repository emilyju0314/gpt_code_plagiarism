BOOST_AUTO_TEST_CASE(LogisticRegressionLBFGSSimpleTest)
{
  // Very simple fake dataset.
  arma::mat data("1 2 3;"
                 "1 2 3");
  arma::Row<size_t> responses("1 1 0");

  // Create a logistic regression object using L-BFGS (that is the default).
  LogisticRegression<> lr(data, responses);

  // Test sigmoid function.
  arma::rowvec sigmoids = 1 / (1 + arma::exp(-lr.Parameters()[0]
      - lr.Parameters().tail_cols(lr.Parameters().n_elem - 1) * data));

  // Large 0.1% error tolerance is because the optimizer may terminate before
  // the predictions converge to 1.
  BOOST_REQUIRE_CLOSE(sigmoids[0], 1.0, 0.1);
  BOOST_REQUIRE_CLOSE(sigmoids[1], 1.0, 5.0);
  BOOST_REQUIRE_SMALL(sigmoids[2], 0.1);
}