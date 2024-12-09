BOOST_AUTO_TEST_CASE(LRPridictionSizeCheck)
{
  constexpr int N = 10;
  constexpr int D = 3;
  constexpr int M = 15;

  arma::mat trainX = arma::randu<arma::mat>(D, N);
  arma::Row<size_t> trainY;
  // 10 responses.
  trainY << 0 << 1 << 0 << 1 << 1 << 1 << 0 << 1 << 0 << 0 << arma::endr;
  arma::mat testX = arma::randu<arma::mat>(D, M);

  SetInputParam("training", std::move(trainX));
  SetInputParam("labels", std::move(trainY));
  SetInputParam("test", std::move(testX));

  // Training the model.
  mlpackMain();

  // Get the output predictions of the test data.
  const arma::Row<size_t> &testY = CLI::GetParam<arma::Row<size_t>>("output");

  // Output predictions size must match the test data set size.
  BOOST_REQUIRE_EQUAL(testY.n_rows, 1);
  BOOST_REQUIRE_EQUAL(testY.n_cols, M);
}