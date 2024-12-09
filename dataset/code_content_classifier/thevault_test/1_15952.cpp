BOOST_AUTO_TEST_CASE(ReparametrizationLayerStochasticTest)
{
  arma::mat input, outputA, outputB;
  Reparametrization<> module(5, false);

  input = join_cols(arma::ones<arma::mat>(5, 1),
      arma::zeros<arma::mat>(5, 1));

  // Test if two forward passes generate same output.
  module.Forward(input, outputA);
  module.Forward(input, outputB);

  CheckMatrices(outputA, outputB);
}