BOOST_AUTO_TEST_CASE(GlimpseLayerParametersTest)
{
  // Parameter order : inSize, size, depth, scale, inputWidth, inputHeight.
  Glimpse<> layer1(1, 2, 3, 4, 5, 6);
  Glimpse<> layer2(1, 2, 3, 4, 6, 7);

  // Make sure we can get the parameters successfully.
  BOOST_REQUIRE_EQUAL(layer1.InputHeight(), 6);
  BOOST_REQUIRE_EQUAL(layer1.InputWidth(), 5);
  BOOST_REQUIRE_EQUAL(layer1.Scale(), 4);
  BOOST_REQUIRE_EQUAL(layer1.Depth(), 3);
  BOOST_REQUIRE_EQUAL(layer1.GlimpseSize(), 2);
  BOOST_REQUIRE_EQUAL(layer1.InSize(), 1);

  // Now modify the parameters to match the second layer.
  layer1.InputHeight() = 7;
  layer1.InputWidth() = 6;

  // Now ensure that all the results are the same.
  BOOST_REQUIRE_EQUAL(layer1.InputHeight(), layer2.InputHeight());
  BOOST_REQUIRE_EQUAL(layer1.InputWidth(), layer2.InputWidth());
  BOOST_REQUIRE_EQUAL(layer1.Scale(), layer2.Scale());
  BOOST_REQUIRE_EQUAL(layer1.Depth(), layer2.Depth());
  BOOST_REQUIRE_EQUAL(layer1.GlimpseSize(), layer2.GlimpseSize());
  BOOST_REQUIRE_EQUAL(layer1.InSize(), layer2.InSize());
}