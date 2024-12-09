BOOST_AUTO_TEST_CASE(LogisticRegressionInstantiatedOptimizer)
{
  // Very simple fake dataset.
  arma::mat data("1 2 3;"
                 "1 2 3");
  arma::Row<size_t> responses("1 1 0");

  // Create an optimizer and function.
  ens::L_BFGS lbfgsOpt;
  lbfgsOpt.MinGradientNorm() = 1e-50;
  LogisticRegression<> lr(data, responses, lbfgsOpt, 0.0005);

  // Test sigmoid function.
  arma::rowvec sigmoids = 1 / (1 + arma::exp(-lr.Parameters()[0]
      - lr.Parameters().tail_cols(lr.Parameters().n_elem - 1) * data));

  // Error tolerance is small because we tightened the optimizer tolerance.
  BOOST_REQUIRE_CLOSE(sigmoids[0], 1.0, 0.1);
  BOOST_REQUIRE_CLOSE(sigmoids[1], 1.0, 0.6);
  BOOST_REQUIRE_SMALL(sigmoids[2], 0.1);

  // Now do the same with SGD.
  ens::StandardSGD sgdOpt;
  sgdOpt.StepSize() = 0.15;
  sgdOpt.Tolerance() = 1e-75;
  LogisticRegression<> lr2(data, responses, sgdOpt, 0.0005);

  // Test sigmoid function.
  sigmoids = 1 / (1 + arma::exp(-lr2.Parameters()[0]
      - lr2.Parameters().tail_cols(lr2.Parameters().n_elem - 1) * data));

  // Error tolerance is small because we tightened the optimizer tolerance.
  BOOST_REQUIRE_CLOSE(sigmoids[0], 1.0, 0.1);
  BOOST_REQUIRE_CLOSE(sigmoids[1], 1.0, 0.6);
  BOOST_REQUIRE_SMALL(sigmoids[2], 0.1);
}