BOOST_AUTO_TEST_CASE(WeightNormRunTest)
{
  arma::mat output, input, delta, error;

  Linear<>* linear = new Linear<>(10, 10);

  WeightNorm<> module(linear);

  module.Parameters().randu();
  module.Reset();

  linear->Bias().zeros();

  input = arma::zeros(10, 1);
  module.Forward(input, output);

  // Test the Backward function.
  module.Backward(input, input, delta);

  BOOST_REQUIRE_EQUAL(0, arma::accu(output));
  BOOST_REQUIRE_EQUAL(arma::accu(delta), 0);
}