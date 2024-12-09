void CheckCELUDerivativeCorrect(const arma::colvec input,
                                const arma::colvec target)
{
  // Initialize CELU object with alpha = 1.0.
  CELU<> lrf(1.0);

  // Test the calculation of the derivatives using the entire vector as input.
  arma::colvec derivatives, activations;

  // This error vector will be set to 1 to get the derivatives.
  arma::colvec error = arma::ones<arma::colvec>(input.n_elem);
  lrf.Forward(input, activations);
  lrf.Backward(activations, error, derivatives);
  for (size_t i = 0; i < derivatives.n_elem; i++)
  {
    BOOST_REQUIRE_CLOSE(derivatives.at(i), target.at(i), 1e-3);
  }
}