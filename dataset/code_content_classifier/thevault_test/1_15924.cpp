BOOST_AUTO_TEST_CASE(SimpleAlphaDropoutLayerTest)
{
  // Initialize the probability of setting a value to alphaDash.
  const double p = 0.2;

  // Initialize the input parameter having a mean nearabout 0
  // and variance nearabout 1.
  arma::mat input = arma::randn<arma::mat>(1000, 1);

  AlphaDropout<> module(p);
  module.Deterministic() = false;

  // Test the Forward function when training phase.
  arma::mat output;
  module.Forward(input, output);
  // Check whether mean remains nearly same.
  BOOST_REQUIRE_LE(
      arma::as_scalar(arma::abs(arma::mean(input) - arma::mean(output))), 0.1);

  // Check whether variance remains nearly same.
  BOOST_REQUIRE_LE(
      arma::as_scalar(arma::abs(arma::var(input) - arma::var(output))), 0.1);

  // Test the Backward function when training phase.
  arma::mat delta;
  module.Backward(input, input, delta);
  BOOST_REQUIRE_LE(
      arma::as_scalar(arma::abs(arma::mean(delta) - 0)), 0.05);

  // Test the Forward function when testing phase.
  module.Deterministic() = true;
  module.Forward(input, output);
  BOOST_REQUIRE_EQUAL(arma::accu(input), arma::accu(output));
}