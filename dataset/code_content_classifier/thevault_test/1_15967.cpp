BOOST_AUTO_TEST_CASE(AdaptiveMeanPoolingTestCase)
{
  // For rectangular input.
  arma::mat input = arma::mat(12, 1);
  arma::mat output, delta;

  input.zeros();
  input(0) = 1;
  input(1) = 2;
  input(2) = 3;
  input(3) = input(8) = 7;
  input(4) = 4;
  input(5) = 5;
  input(6) = input(7) = 6;
  input(10) = 8;
  input(11) = 9;
  // Output-Size should be 2 x 2.
  // Square output.
  AdaptiveMeanPooling<> module1(2, 2);
  module1.InputHeight() = 3;
  module1.InputWidth() = 4;
  module1.Forward(input, output);
  // Calculated using torch.nn.AdaptiveAvgPool2d().
  BOOST_REQUIRE_EQUAL(arma::accu(output), 19.75);
  BOOST_REQUIRE_EQUAL(output.n_elem, 4);
  BOOST_REQUIRE_EQUAL(output.n_cols, 1);
  // Test the Backward Function.
  module1.Backward(input, output, delta);
  BOOST_REQUIRE_EQUAL(arma::accu(delta), 7.0);

  // For Square input.
  input = arma::mat(9, 1);
  input.zeros();
  input(0) = 6;
  input(1) = 3;
  input(2) = 9;
  input(3) = 3;
  input(6) = 3;
  // Output-Size should be 1 x 2.
  // Rectangular output.
  AdaptiveMeanPooling<> module2(1, 2);
  module2.InputHeight() = 3;
  module2.InputWidth() = 3;
  module2.Forward(input, output);
  // Calculated using torch.nn.AdaptiveAvgPool2d().
  BOOST_REQUIRE_EQUAL(arma::accu(output), 4.5);
  BOOST_REQUIRE_EQUAL(output.n_elem, 2);
  BOOST_REQUIRE_EQUAL(output.n_cols, 1);
  // Test the Backward Function.
  module2.Backward(input, output, delta);
  BOOST_REQUIRE_EQUAL(arma::accu(delta), 0.0);

  // For Square input.
  input = arma::mat(16, 1);
  input.zeros();
  input(0) = 6;
  input(1) = 3;
  input(2) = 9;
  input(4) = 3;
  input(8) = 3;
  // Output-Size should be 3 x 3.
  // Square output.
  AdaptiveMeanPooling<> module3(std::tuple<size_t, size_t>(3, 3));
  module3.InputHeight() = 4;
  module3.InputWidth() = 4;
  module3.Forward(input, output);
  // Calculated using torch.nn.AdaptiveAvgPool2d().
  BOOST_REQUIRE_EQUAL(arma::accu(output), 10.5);
  BOOST_REQUIRE_EQUAL(output.n_elem, 9);
  BOOST_REQUIRE_EQUAL(output.n_cols, 1);
  // Test the Backward Function.
  module3.Backward(input, output, delta);
  BOOST_REQUIRE_EQUAL(arma::accu(delta), 10.5);

  // For Rectangular input.
  input = arma::mat(24, 1);
  input.zeros();
  input(0) = 3;
  input(1) = 3;
  input(4) = 3;
  // Output-Size should be 3 x 3.
  // Square output.
  AdaptiveMeanPooling<> module4(std::tuple<size_t, size_t>(3, 3));
  module4.InputHeight() = 4;
  module4.InputWidth() = 6;
  module4.Forward(input, output);
  // Calculated using torch.nn.AdaptiveAvgPool2d().
  BOOST_REQUIRE_EQUAL(arma::accu(output), 2.25);
  BOOST_REQUIRE_EQUAL(output.n_elem, 9);
  BOOST_REQUIRE_EQUAL(output.n_cols, 1);
  // Test the Backward Function.
  module4.Backward(input, output, delta);
  BOOST_REQUIRE_EQUAL(arma::accu(delta), 1.5);
}