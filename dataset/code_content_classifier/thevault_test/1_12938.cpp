BOOST_AUTO_TEST_CASE(LogisticRegressionFunctionSeparableGradient)
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
  lrf.Gradient(arma::rowvec("200 -40 -40"), 0, gradient, 1);

  BOOST_REQUIRE_EQUAL(gradient.n_elem, 3);
  BOOST_REQUIRE_SMALL(gradient[0], 1e-15);
  BOOST_REQUIRE_SMALL(gradient[1], 1e-15);
  BOOST_REQUIRE_SMALL(gradient[2], 1e-15);

  lrf.Gradient(arma::rowvec("200 -40 -40"), 1, gradient, 1);
  BOOST_REQUIRE_EQUAL(gradient.n_elem, 3);
  BOOST_REQUIRE_SMALL(gradient[0], 1e-15);
  BOOST_REQUIRE_SMALL(gradient[1], 1e-15);
  BOOST_REQUIRE_SMALL(gradient[2], 1e-15);

  lrf.Gradient(arma::rowvec("200 -40 -40"), 2, gradient, 1);
  BOOST_REQUIRE_EQUAL(gradient.n_elem, 3);
  BOOST_REQUIRE_SMALL(gradient[0], 1e-15);
  BOOST_REQUIRE_SMALL(gradient[1], 1e-15);
  BOOST_REQUIRE_SMALL(gradient[2], 1e-15);

  // Perturb two elements in the wrong way, so they need to become smaller.  For
  // the first two data points, classification is still correct so the gradient
  // should be zero.
  lrf.Gradient(arma::rowvec("200 -30 -30"), 0, gradient, 1);
  BOOST_REQUIRE_EQUAL(gradient.n_elem, 3);
  BOOST_REQUIRE_SMALL(gradient[0], 1e-15);
  BOOST_REQUIRE_SMALL(gradient[1], 1e-15);
  BOOST_REQUIRE_SMALL(gradient[2], 1e-15);

  lrf.Gradient(arma::rowvec("200 -30 -30"), 1, gradient, 1);
  BOOST_REQUIRE_EQUAL(gradient.n_elem, 3);
  BOOST_REQUIRE_SMALL(gradient[0], 1e-15);
  BOOST_REQUIRE_SMALL(gradient[1], 1e-15);
  BOOST_REQUIRE_SMALL(gradient[2], 1e-15);

  lrf.Gradient(arma::rowvec("200 -30 -30"), 2, gradient, 1);
  BOOST_REQUIRE_EQUAL(gradient.n_elem, 3);
  BOOST_REQUIRE_GE(gradient[1], 0.0);
  BOOST_REQUIRE_GE(gradient[2], 0.0);

  // Perturb two elements in the other wrong way, so they need to become larger.
  // For the first and last data point, classification is still correct so the
  // gradient should be zero.
  lrf.Gradient(arma::rowvec("200 -60 -60"), 0, gradient, 1);
  BOOST_REQUIRE_EQUAL(gradient.n_elem, 3);
  BOOST_REQUIRE_SMALL(gradient[0], 1e-15);
  BOOST_REQUIRE_SMALL(gradient[1], 1e-15);
  BOOST_REQUIRE_SMALL(gradient[2], 1e-15);

  lrf.Gradient(arma::rowvec("200 -30 -30"), 1, gradient, 1);
  BOOST_REQUIRE_EQUAL(gradient.n_elem, 3);
  BOOST_REQUIRE_LE(gradient[1], 0.0);
  BOOST_REQUIRE_LE(gradient[2], 0.0);

  lrf.Gradient(arma::rowvec("200 -60 -60"), 2, gradient, 1);
  BOOST_REQUIRE_EQUAL(gradient.n_elem, 3);
  BOOST_REQUIRE_SMALL(gradient[0], 1e-15);
  BOOST_REQUIRE_SMALL(gradient[1], 1e-15);
  BOOST_REQUIRE_SMALL(gradient[2], 1e-15);
}