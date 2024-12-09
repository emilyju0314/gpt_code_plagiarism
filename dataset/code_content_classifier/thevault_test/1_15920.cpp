BOOST_AUTO_TEST_CASE(AddLayerParametersTest)
{
  // Parameter : outSize.
  Add<> layer(7);

  // Make sure we can get the parameter successfully.
  BOOST_REQUIRE_EQUAL(layer.OutputSize(), 7);
}