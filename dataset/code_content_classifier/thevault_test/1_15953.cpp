BOOST_AUTO_TEST_CASE(ReparametrizationLayerIncludeKlTest)
{
  arma::mat input, output, gy, delta;
  Reparametrization<> module(5, true, false);

  input = join_cols(arma::ones<arma::mat>(5, 1),
      arma::zeros<arma::mat>(5, 1));
  module.Forward(input, output);

  // As KL divergence is not included, with the above inputs, the delta
  // matrix should be all zeros.
  gy = arma::zeros(output.n_rows, output.n_cols);
  module.Backward(output, gy, delta);

  BOOST_REQUIRE_EQUAL(arma::accu(delta), 0);
}