BOOST_AUTO_TEST_CASE(LookupLayerParametersTest)
{
  // Parameter order : inSize, outSize.
  Lookup<> layer(5, 7);

  // Make sure we can get the parameters successfully.
  BOOST_REQUIRE_EQUAL(layer.InSize(), 5);
  BOOST_REQUIRE_EQUAL(layer.OutSize(), 7);
}