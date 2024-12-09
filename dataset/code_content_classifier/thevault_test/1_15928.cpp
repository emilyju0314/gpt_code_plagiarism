BOOST_AUTO_TEST_CASE(SelectLayerParametersTest)
{
  // Parameter order : index, elements.
  Select<> layer(3, 5);

  // Make sure we can get the parameters successfully.
  BOOST_REQUIRE_EQUAL(layer.Index(), 3);
  BOOST_REQUIRE_EQUAL(layer.NumElements(), 5);
}