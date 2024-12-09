BOOST_AUTO_TEST_CASE(LogisticRegressionFunctionRegularizationEvaluate)
{
  const size_t points = 5000;
  const size_t dimension = 25;
  const size_t trials = 10;

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
    // the first parameters term is ignored).
    const double smallRegTerm = 0.25 * std::pow(arma::norm(parameters, 2), 2.0)
        - 0.25 * std::pow(parameters[0], 2.0);
    const double bigRegTerm = 10.0 * std::pow(arma::norm(parameters, 2), 2.0)
        - 10.0 * std::pow(parameters[0], 2.0);

    BOOST_REQUIRE_CLOSE(lrfNoReg.Evaluate(parameters) + smallRegTerm,
        lrfSmallReg.Evaluate(parameters), 1e-5);
    BOOST_REQUIRE_CLOSE(lrfNoReg.Evaluate(parameters) + bigRegTerm,
        lrfBigReg.Evaluate(parameters), 1e-5);
  }
}