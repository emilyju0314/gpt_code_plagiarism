BOOST_AUTO_TEST_CASE(LogisticRegressionFunctionGradient)
{
  // Very simple fake dataset.
  arma::mat data("1 2 3;"
                 "1 2 3");
  arma::Row<size_t> responses("1 1 0");

  // Create a LogisticRegressionFunction.
  LogisticRegressionFunction<> lrf(data, responses,
      0.0 /* no regularization */);
  arma::rowvec gradient;

  // If the model is at the optimum, then the gradient should be zero.
  lrf.Gradient(arma::rowvec("200 -40 -40"), gradient);

  BOOST_REQUIRE_EQUAL(gradient.n_elem, 3);
  BOOST_REQUIRE_SMALL(gradient[0], 1e-15);
  BOOST_REQUIRE_SMALL(gradient[1], 1e-15);
  BOOST_REQUIRE_SMALL(gradient[2], 1e-15);

  // Perturb two elements in the wrong way, so they need to become smaller.
  lrf.Gradient(arma::rowvec("200 -20 -20"), gradient);

  // The actual values are less important; the gradient just needs to be pointed
  // the right way.
  BOOST_REQUIRE_EQUAL(gradient.n_elem, 3);
  BOOST_REQUIRE_GE(gradient[1], 0.0);
  BOOST_REQUIRE_GE(gradient[2], 0.0);

  // Perturb two elements in the wrong way, so they need to become larger.
  lrf.Gradient(arma::rowvec("200 -60 -60"), gradient);

  // The actual values are less important; the gradient just needs to be pointed
  // the right way.
  BOOST_REQUIRE_EQUAL(gradient.n_elem, 3);
  BOOST_REQUIRE_LE(gradient[1], 0.0);
  BOOST_REQUIRE_LE(gradient[2], 0.0);

  // Perturb the intercept element.
  lrf.Gradient(arma::rowvec("250 -40 -40"), gradient);

  // The actual values are less important; the gradient just needs to be pointed
  // the right way.
  BOOST_REQUIRE_EQUAL(gradient.n_elem, 3);
  BOOST_REQUIRE_GE(gradient[0], 0.0);
}