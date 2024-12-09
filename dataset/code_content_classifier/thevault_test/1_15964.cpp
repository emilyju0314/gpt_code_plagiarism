BOOST_AUTO_TEST_CASE(ReinforceNormalLayerParametersTest)
{
  // Parameter : stdev.
  ReinforceNormal<> layer(4.0);

  // Make sure we can get the parameter successfully.
  BOOST_REQUIRE_EQUAL(layer.StandardDeviation(), 4.0);
}