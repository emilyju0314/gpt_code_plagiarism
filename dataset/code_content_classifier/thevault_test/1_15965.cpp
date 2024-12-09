BOOST_AUTO_TEST_CASE(VRClassRewardLayerParametersTest)
{
  // Parameter order : scale, sizeAverage.
  VRClassReward<> layer(2, false);

  // Make sure we can get the parameters successfully.
  BOOST_REQUIRE_EQUAL(layer.Scale(), 2);
  BOOST_REQUIRE_EQUAL(layer.SizeAverage(), false);
}