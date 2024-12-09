BOOST_AUTO_TEST_CASE(SimpleAtrousConvolutionLayerTest)
{
  arma::mat output, input, delta;

  AtrousConvolution<> module1(1, 1, 3, 3, 1, 1, 0, 0, 7, 7, 2, 2);
  // Test the Forward function.
  input = arma::linspace<arma::colvec>(0, 48, 49);
  module1.Parameters() = arma::mat(9 + 1, 1, arma::fill::zeros);
  module1.Parameters()(0) = 1.0;
  module1.Parameters()(8) = 2.0;
  module1.Reset();
  module1.Forward(input, output);
  // Value calculated using tensorflow.nn.atrous_conv2d()
  BOOST_REQUIRE_EQUAL(arma::accu(output), 792.0);

  // Test the Backward function.
  module1.Backward(input, output, delta);
  BOOST_REQUIRE_EQUAL(arma::accu(delta), 2376);

  AtrousConvolution<> module2(1, 1, 3, 3, 2, 2, 0, 0, 7, 7, 2, 2);
  // Test the forward function.
  input = arma::linspace<arma::colvec>(0, 48, 49);
  module2.Parameters() = arma::mat(9 + 1, 1, arma::fill::zeros);
  module2.Parameters()(0) = 1.0;
  module2.Parameters()(3) = 1.0;
  module2.Parameters()(6) = 1.0;
  module2.Reset();
  module2.Forward(input, output);
  // Value calculated using tensorflow.nn.conv2d()
  BOOST_REQUIRE_EQUAL(arma::accu(output), 264.0);

  // Test the backward function.
  module2.Backward(input, output, delta);
  BOOST_REQUIRE_EQUAL(arma::accu(delta), 792.0);
}