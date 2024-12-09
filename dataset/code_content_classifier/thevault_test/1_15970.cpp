void CheckPReLUActivationCorrect(const arma::colvec input,
                                 const arma::colvec target)
{
  PReLU<> prelu;

  // Test the activation function using the entire vector as input.
  arma::colvec activations;
  prelu.Forward(input, activations);
  for (size_t i = 0; i < activations.n_elem; i++)
  {
    BOOST_REQUIRE_CLOSE(activations.at(i), target.at(i), 1e-3);
  }
}