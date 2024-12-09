BOOST_AUTO_TEST_CASE(MaxPoolingTestCase)
{
  // For rectangular input to pooling layers.
  arma::mat input = arma::mat(12, 1);
  arma::mat output;
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
  MaxPooling<> module1(2, 2, 2, 1);
  module1.InputHeight() = 3;
  module1.InputWidth() = 4;
  module1.Forward(input, output);
  // Calculated using torch.nn.MaxPool2d().
  BOOST_REQUIRE_EQUAL(arma::accu(output), 28);
  BOOST_REQUIRE_EQUAL(output.n_elem, 4);
  BOOST_REQUIRE_EQUAL(output.n_cols, 1);

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
  MaxPooling<> module2(3, 2, 3, 1);
  module2.InputHeight() = 3;
  module2.InputWidth() = 3;
  module2.Forward(input, output);
  // Calculated using torch.nn.MaxPool2d().
  BOOST_REQUIRE_EQUAL(arma::accu(output), 12.0);
  BOOST_REQUIRE_EQUAL(output.n_elem, 2);
  BOOST_REQUIRE_EQUAL(output.n_cols, 1);

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
  MaxPooling<> module3(2, 2, 1, 1);
  module3.InputHeight() = 4;
  module3.InputWidth() = 4;
  module3.Forward(input, output);
  // Calculated using torch.nn.MaxPool2d().
  BOOST_REQUIRE_EQUAL(arma::accu(output), 30.0);
  BOOST_REQUIRE_EQUAL(output.n_elem, 9);
  BOOST_REQUIRE_EQUAL(output.n_cols, 1);

  // For Rectangular input.
  input = arma::mat(6, 1);
  input.zeros();
  input(0) = 1;
  input(1) = 1;
  input(3) = 1;
  // Output-Size should be 2 x 2.
  // Square output.
  MaxPooling<> module4(2, 1, 1, 1);
  module4.InputHeight() = 2;
  module4.InputWidth() = 3;
  module4.Forward(input, output);
  // Calculated using torch.nn.MaxPool2d().
  BOOST_REQUIRE_EQUAL(arma::accu(output), 3);
  BOOST_REQUIRE_EQUAL(output.n_elem, 4);
  BOOST_REQUIRE_EQUAL(output.n_cols, 1);
}