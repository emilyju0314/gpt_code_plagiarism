BOOST_AUTO_TEST_CASE(HighwayLayerParametersTest)
{
  // Parameter order : inSize, model.
  Highway<> layer(1, true);

  // Make sure we can get the parameter successfully.
  BOOST_REQUIRE_EQUAL(layer.InSize(), 1);
}