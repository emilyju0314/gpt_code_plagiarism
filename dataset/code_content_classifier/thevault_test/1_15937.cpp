BOOST_AUTO_TEST_CASE(ConcatLayerParametersTest)
{
  // Parameter order : inputSize{width, height, channels}, axis, model, run.
  arma::Row<size_t> inputSize{128, 128, 3};
  Concat<> layer(inputSize, 2, false, true);

  // Make sure we can get the parameters successfully.
  BOOST_REQUIRE_EQUAL(layer.ConcatAxis(), 2);
}