BOOST_AUTO_TEST_CASE(GRULayerParametersTest)
{
  // Parameter order : inSize, outSize, rho.
  GRU<> layer1(1, 2, 3);
  GRU<> layer2(1, 2, 4);

  // Make sure we can get the parameters successfully.
  BOOST_REQUIRE_EQUAL(layer1.InSize(), 1);
  BOOST_REQUIRE_EQUAL(layer1.OutSize(), 2);
  BOOST_REQUIRE_EQUAL(layer1.Rho(), 3);

  // Now modify the parameters to match the second layer.
  layer1.Rho() = 4;

  // Now ensure all the results are the same.
  BOOST_REQUIRE_EQUAL(layer1.InSize(), layer2.InSize());
  BOOST_REQUIRE_EQUAL(layer2.OutSize(), layer2.OutSize());
  BOOST_REQUIRE_EQUAL(layer1.Rho(), layer2.Rho());
}