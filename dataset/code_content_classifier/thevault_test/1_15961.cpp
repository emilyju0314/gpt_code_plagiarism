BOOST_AUTO_TEST_CASE(TransposedConvolutionLayerPaddingTest)
{
  arma::mat output, input, delta;

  TransposedConvolution<> module1(1, 1, 3, 3, 1, 1, 0, 0, 4, 4, 6, 6, "VALID");
  // Test the forward function.
  // Valid Should give the same result.
  input = arma::linspace<arma::colvec>(0, 15, 16);
  module1.Parameters() = arma::mat(9 + 1, 1, arma::fill::zeros);
  module1.Reset();
  module1.Forward(input, output);
  // Value calculated using tensorflow.nn.conv2d_transpose().
  BOOST_REQUIRE_EQUAL(arma::accu(output), 0.0);

  // Test the Backward Function.
  module1.Backward(input, output, delta);
  BOOST_REQUIRE_EQUAL(arma::accu(delta), 0.0);

  // Test Valid for non zero padding.
  TransposedConvolution<> module2(1, 1, 3, 3, 2, 2,
      std::tuple<size_t, size_t>(0, 0), std::tuple<size_t, size_t>(0, 0),
      2, 2, 5, 5, "VALID");
  // Test the forward function.
  input = arma::linspace<arma::colvec>(0, 3, 4);
  module2.Parameters() = arma::mat(25 + 1, 1, arma::fill::zeros);
  module2.Parameters()(2) = 8.0;
  module2.Parameters()(4) = 6.0;
  module2.Parameters()(6) = 4.0;
  module2.Parameters()(8) = 2.0;
  module2.Reset();
  module2.Forward(input, output);
  // Value calculated using torch.nn.functional.conv_transpose2d().
  BOOST_REQUIRE_EQUAL(arma::accu(output), 120.0);

  // Test the Backward Function.
  module2.Backward(input, output, delta);
  BOOST_REQUIRE_EQUAL(arma::accu(delta), 960.0);

  // Test for same padding type.
  TransposedConvolution<> module3(1, 1, 3, 3, 2, 2, 0, 0, 3, 3, 3, 3, "SAME");
  // Test the forward function.
  input = arma::linspace<arma::colvec>(0, 8, 9);
  module3.Parameters() = arma::mat(9 + 1, 1, arma::fill::zeros);
  module3.Reset();
  module3.Forward(input, output);
  BOOST_REQUIRE_EQUAL(arma::accu(output), 0);
  BOOST_REQUIRE_EQUAL(output.n_rows, input.n_rows);
  BOOST_REQUIRE_EQUAL(output.n_cols, input.n_cols);

  // Test the Backward Function.
  module3.Backward(input, output, delta);
  BOOST_REQUIRE_EQUAL(arma::accu(delta), 0.0);

  // Output shape should equal input.
  TransposedConvolution<> module4(1, 1, 3, 3, 1, 1,
    std::tuple<size_t, size_t>(2, 2), std::tuple<size_t, size_t>(2, 2),
    5, 5, 5, 5, "SAME");
  // Test the forward function.
  input = arma::linspace<arma::colvec>(0, 24, 25);
  module4.Parameters() = arma::mat(9 + 1, 1, arma::fill::zeros);
  module4.Reset();
  module4.Forward(input, output);
  BOOST_REQUIRE_EQUAL(arma::accu(output), 0);
  BOOST_REQUIRE_EQUAL(output.n_rows, input.n_rows);
  BOOST_REQUIRE_EQUAL(output.n_cols, input.n_cols);

  // Test the Backward Function.
  module4.Backward(input, output, delta);
  BOOST_REQUIRE_EQUAL(arma::accu(delta), 0.0);

  TransposedConvolution<> module5(1, 1, 3, 3, 2, 2, 0, 0, 2, 2, 2, 2, "SAME");
  // Test the forward function.
  input = arma::linspace<arma::colvec>(0, 3, 4);
  module5.Parameters() = arma::mat(25 + 1, 1, arma::fill::zeros);
  module5.Reset();
  module5.Forward(input, output);
  BOOST_REQUIRE_EQUAL(arma::accu(output), 0);
  BOOST_REQUIRE_EQUAL(output.n_rows, input.n_rows);
  BOOST_REQUIRE_EQUAL(output.n_cols, input.n_cols);

  // Test the Backward Function.
  module5.Backward(input, output, delta);
  BOOST_REQUIRE_EQUAL(arma::accu(delta), 0.0);

  TransposedConvolution<> module6(1, 1, 4, 4, 1, 1, 1, 1, 5, 5, 5, 5, "SAME");
  // Test the forward function.
  input = arma::linspace<arma::colvec>(0, 24, 25);
  module6.Parameters() = arma::mat(16 + 1, 1, arma::fill::zeros);
  module6.Reset();
  module6.Forward(input, output);
  BOOST_REQUIRE_EQUAL(arma::accu(output), 0);
  BOOST_REQUIRE_EQUAL(output.n_rows, input.n_rows);
  BOOST_REQUIRE_EQUAL(output.n_cols, input.n_cols);

  // Test the Backward Function.
  module6.Backward(input, output, delta);
  BOOST_REQUIRE_EQUAL(arma::accu(delta), 0.0);
}