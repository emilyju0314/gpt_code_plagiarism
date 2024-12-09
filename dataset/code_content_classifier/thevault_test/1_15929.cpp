BOOST_AUTO_TEST_CASE(SimpleAddMergeLayerTest)
{
  arma::mat output, input, delta;
  input = arma::ones(10, 1);

  for (size_t i = 0; i < 5; ++i)
  {
    AddMerge<> module(false, false);
    const size_t numMergeModules = math::RandInt(2, 10);
    for (size_t m = 0; m < numMergeModules; ++m)
    {
      IdentityLayer<> identityLayer;
      identityLayer.Forward(input, identityLayer.OutputParameter());

      module.Add<IdentityLayer<> >(identityLayer);
    }

    // Test the Forward function.
    module.Forward(input, output);
    BOOST_REQUIRE_EQUAL(10 * numMergeModules, arma::accu(output));

    // Test the Backward function.
    module.Backward(input, output, delta);
    BOOST_REQUIRE_EQUAL(arma::accu(output), arma::accu(delta));
  }
}