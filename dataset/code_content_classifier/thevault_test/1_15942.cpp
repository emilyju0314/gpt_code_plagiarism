BOOST_AUTO_TEST_CASE(BatchNormLayerParametersTest)
{
  // Parameter order : size, eps.
  BatchNorm<> layer(7, 1e-3);

  // Make sure we can get the parameters successfully.
  BOOST_REQUIRE_EQUAL(layer.InputSize(), 7);
  BOOST_REQUIRE_EQUAL(layer.Epsilon(), 1e-3);
}