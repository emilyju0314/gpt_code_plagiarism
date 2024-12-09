BOOST_AUTO_TEST_CASE(VirtualBatchNormLayerParametersTest)
{
  arma::mat input = arma::randn(5, 256);
  arma::mat referenceBatch = arma::mat(input.memptr(), input.n_rows, 16);

  // Parameter order : referenceBatch, size, eps.
  VirtualBatchNorm<> layer(referenceBatch, 5, 1e-3);

  // Make sure we can get the parameters successfully.
  BOOST_REQUIRE_EQUAL(layer.InSize(), 5);
  BOOST_REQUIRE_EQUAL(layer.Epsilon(), 1e-3);
}