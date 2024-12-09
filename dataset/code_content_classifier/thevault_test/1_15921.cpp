BOOST_AUTO_TEST_CASE(ConstantLayerParametersTest)
{
  // Parameter : outSize.
  Constant<> layer(7);

  // Make sure we can get the parameter successfully.
  BOOST_REQUIRE_EQUAL(layer.OutSize(), 7);
}