BOOST_AUTO_TEST_CASE(AtrousConvolutionLayerPaddingTest)
{
  arma::mat output, input, delta;

  // Check valid padding option.
  AtrousConvolution<> module1(1, 1, 3, 3, 1, 1,
      std::tuple<size_t, size_t>(1, 1), std::tuple<size_t, size_t>(1, 1), 7, 7,
      2, 2, "valid");

  // Test the Forward function.
  input = arma::linspace<arma::colvec>(0, 48, 49);
  module1.Parameters() = arma::mat(9 + 1, 1, arma::fill::zeros);
  module1.Reset();
  module1.Forward(input, output);

  BOOST_REQUIRE_EQUAL(arma::accu(output), 0);
  BOOST_REQUIRE_EQUAL(output.n_rows, 9);
  BOOST_REQUIRE_EQUAL(output.n_cols, 1);

  // Test the Backward function.
  module1.Backward(input, output, delta);

  // Check same padding option.
  AtrousConvolution<> module2(1, 1, 3, 3, 1, 1,
      std::tuple<size_t, size_t>(0, 0), std::tuple<size_t, size_t>(0, 0), 7, 7,
      2, 2, "same");

  // Test the forward function.
  input = arma::linspace<arma::colvec>(0, 48, 49);
  module2.Parameters() = arma::mat(9 + 1, 1, arma::fill::zeros);
  module2.Reset();
  module2.Forward(input, output);

  BOOST_REQUIRE_EQUAL(arma::accu(output), 0);
  BOOST_REQUIRE_EQUAL(output.n_rows, 49);
  BOOST_REQUIRE_EQUAL(output.n_cols, 1);

  // Test the backward function.
  module2.Backward(input, output, delta);
}