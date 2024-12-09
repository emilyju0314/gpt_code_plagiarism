BOOST_AUTO_TEST_CASE(SubviewLayerParametersTest)
{
  // Parameter order : inSize, beginRow, endRow, beginCol, endCol.
  Subview<> layer1(1, 2, 3, 4, 5);
  Subview<> layer2(1, 3, 4, 5, 6);

  // Make sure we can get the parameters correctly.
  BOOST_REQUIRE_EQUAL(layer1.InSize(), 1);
  BOOST_REQUIRE_EQUAL(layer1.BeginRow(), 2);
  BOOST_REQUIRE_EQUAL(layer1.EndRow(), 3);
  BOOST_REQUIRE_EQUAL(layer1.BeginCol(), 4);
  BOOST_REQUIRE_EQUAL(layer1.EndCol(), 5);

  // Now modify the parameters to match the second layer.
  layer1.BeginRow() = 3;
  layer1.EndRow() = 4;
  layer1.BeginCol() = 5;
  layer1.EndCol() = 6;

  // Now ensure all results are the same.
  BOOST_REQUIRE_EQUAL(layer1.InSize(), layer2.InSize());
  BOOST_REQUIRE_EQUAL(layer1.BeginRow(), layer2.BeginRow());
  BOOST_REQUIRE_EQUAL(layer1.EndRow(), layer2.EndRow());
  BOOST_REQUIRE_EQUAL(layer1.BeginCol(), layer2.BeginCol());
  BOOST_REQUIRE_EQUAL(layer1.EndCol(), layer2.EndCol());
}