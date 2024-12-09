BOOST_AUTO_TEST_CASE(AddMergeRunTest)
{
  arma::mat output, input, delta, error;

  AddMerge<> module(true, true);

  Linear<>* linear = new Linear<>(10, 10);
  module.Add(linear);

  linear->Parameters().randu();
  linear->Reset();

  input = arma::zeros(10, 1);
  module.Forward(input, output);

  double parameterSum = arma::accu(linear->Parameters().submat(
      100, 0, linear->Parameters().n_elem - 1, 0));

  // Test the Backward function.
  module.Backward(input, input, delta);

  // Clean up before we break,
  delete linear;

  BOOST_REQUIRE_CLOSE(parameterSum, arma::accu(output), 1e-3);
  BOOST_REQUIRE_EQUAL(arma::accu(delta), 0);
}