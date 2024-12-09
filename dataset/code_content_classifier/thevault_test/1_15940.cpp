BOOST_AUTO_TEST_CASE(BilinearInterpolationLayerParametersTest)
{
  // Parameter order : inRowSize, inColSize, outRowSize, outColSize, depth.
  BilinearInterpolation<> layer1(1, 2, 3, 4, 5);
  BilinearInterpolation<> layer2(2, 3, 4, 5, 6);

  // Make sure we can get the parameters successfully.
  BOOST_REQUIRE_EQUAL(layer1.InRowSize(), 1);
  BOOST_REQUIRE_EQUAL(layer1.InColSize(), 2);
  BOOST_REQUIRE_EQUAL(layer1.OutRowSize(), 3);
  BOOST_REQUIRE_EQUAL(layer1.OutColSize(), 4);
  BOOST_REQUIRE_EQUAL(layer1.InDepth(), 5);

  // Now modify the parameters to match the second layer.
  layer1.InRowSize() = 2;
  layer1.InColSize() = 3;
  layer1.OutRowSize() = 4;
  layer1.OutColSize() = 5;
  layer1.InDepth() = 6;

  // Now ensure all results are the same.
  BOOST_REQUIRE_EQUAL(layer1.InRowSize(), layer2.InRowSize());
  BOOST_REQUIRE_EQUAL(layer1.InColSize(), layer2.InColSize());
  BOOST_REQUIRE_EQUAL(layer1.OutRowSize(), layer2.OutRowSize());
  BOOST_REQUIRE_EQUAL(layer1.OutColSize(), layer2.OutColSize());
  BOOST_REQUIRE_EQUAL(layer1.InDepth(), layer2.InDepth());
}