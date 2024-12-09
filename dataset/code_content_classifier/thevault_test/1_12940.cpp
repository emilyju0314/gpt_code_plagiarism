BOOST_AUTO_TEST_CASE(LogisticRegressionFunctionRegularizationSeparableGradient)
{
  const size_t points = 2000;
  const size_t dimension = 25;
  const size_t trials = 3;

  // Create a random dataset.
  arma::mat data;
  data.randu(dimension, points);
  // Create random responses.
  arma::Row<size_t> responses(points);
  for (size_t i = 0; i < points; ++i)
    responses[i] = math::RandInt(0, 2);

  LogisticRegressionFunction<> lrfNoReg(data, responses, 0.0);
  LogisticRegressionFunction<> lrfSmallReg(data, responses, 0.5);
  LogisticRegressionFunction<> lrfBigReg(data, responses, 20.0);

  for (size_t i = 0; i < trials; ++i)
  {
    arma::rowvec parameters(dimension + 1);
    parameters.randu();

    // Regularization term: 0.5 * lambda * || parameters ||_2^2 (but note that
    // the first parameters term is ignored).  Now we take the gradient of this
    // to obtain
    //   g[i] = lambda * parameters[i]
    // although g(0) == 0 because we are not regularizing the intercept term of
    // the model.
    arma::rowvec gradient;
    arma::rowvec smallRegGradient;
    arma::rowvec bigRegGradient;

    // Test separable gradient for each point.  Regularization will be the same.
    for (size_t k = 0; k < points; ++k)
    {
      lrfNoReg.Gradient(parameters, k, gradient, 1);
      lrfSmallReg.Gradient(parameters, k, smallRegGradient, 1);
      lrfBigReg.Gradient(parameters, k, bigRegGradient, 1);

      // Check sizes of gradients.
      BOOST_REQUIRE_EQUAL(gradient.n_elem, parameters.n_elem);
      BOOST_REQUIRE_EQUAL(smallRegGradient.n_elem, parameters.n_elem);
      BOOST_REQUIRE_EQUAL(bigRegGradient.n_elem, parameters.n_elem);

      // Make sure first term has zero regularization.
      BOOST_REQUIRE_CLOSE(gradient[0], smallRegGradient[0], 1e-5);
      BOOST_REQUIRE_CLOSE(gradient[0], bigRegGradient[0], 1e-5);

      // Check other terms.
      for (size_t j = 1; j < parameters.n_elem; ++j)
      {
        const double smallRegTerm = 0.5 * parameters[j] / points;
        const double bigRegTerm = 20.0 * parameters[j] / points;

        BOOST_REQUIRE_CLOSE(gradient[j] + smallRegTerm, smallRegGradient[j],
            1e-5);
        BOOST_REQUIRE_CLOSE(gradient[j] + bigRegTerm, bigRegGradient[j], 1e-5);
      }
    }
  }
}