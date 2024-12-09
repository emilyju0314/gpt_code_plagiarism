void CheckELUActivationCorrect(const arma::colvec input,
                               const arma::colvec target)
{
  // Initialize ELU object with alpha = 1.0.
  ELU<> lrf(1.0);

  // Test the activation function using the entire vector as input.
  arma::colvec activations;
  lrf.Forward(input, activations);
  for (size_t i = 0; i < activations.n_elem; i++)
  {
    BOOST_REQUIRE_CLOSE(activations.at(i), target.at(i), 1e-3);
  }
}