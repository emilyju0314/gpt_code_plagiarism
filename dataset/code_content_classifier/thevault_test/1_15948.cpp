BOOST_AUTO_TEST_CASE(LayerNormLayerParametersTest)
{
  // Parameter order : size, eps.
  LayerNorm<> layer(5, 1e-3);

  // Make sure we can get the parameters successfully.
  BOOST_REQUIRE_EQUAL(layer.InSize(), 5);
  BOOST_REQUIRE_EQUAL(layer.Epsilon(), 1e-3);
}