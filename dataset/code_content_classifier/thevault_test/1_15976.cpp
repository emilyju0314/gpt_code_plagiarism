BOOST_AUTO_TEST_CASE(CReLUFunctionTest)
{
  const arma::colvec desiredActivations("0 3.2 4.5 0 \
                                         1 0 2 0 2 0 0 \
                                         100.2 0 1 0 0");

  const arma::colvec desiredDerivatives("0 0 0 0 \
                                         0 0 0 0");
  CReLU<> crelu;
  // Test the activation function using the entire vector as input.
  arma::colvec activations;
  crelu.Forward(activationData, activations);
  arma::colvec derivatives;
  // This error vector will be set to 1 to get the derivatives.
  arma::colvec error = arma::ones<arma::colvec>(desiredActivations.n_elem);
  crelu.Backward(desiredActivations, error, derivatives);
  for (size_t i = 0; i < activations.n_elem; i++)
  {
    BOOST_REQUIRE_CLOSE(activations.at(i), desiredActivations.at(i), 1e-3);
  }
  for (size_t i = 0; i < derivatives.n_elem; i++)
  {
    BOOST_REQUIRE_CLOSE(derivatives.at(i), desiredDerivatives.at(i), 1e-3);
  }
}