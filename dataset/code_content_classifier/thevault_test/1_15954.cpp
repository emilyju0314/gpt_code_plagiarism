BOOST_AUTO_TEST_CASE(ReparametrizationLayerParametersTest)
{
  // Parameter order : latentSize, stochastic, includeKL, beta.
  Reparametrization<> layer(5, false, false, 2);

  // Make sure we can get the parameters successfully.
  BOOST_REQUIRE_EQUAL(layer.OutputSize(), 5);
  BOOST_REQUIRE_EQUAL(layer.Stochastic(), false);
  BOOST_REQUIRE_EQUAL(layer.IncludeKL(), false);
  BOOST_REQUIRE_EQUAL(layer.Beta(), 2);
}