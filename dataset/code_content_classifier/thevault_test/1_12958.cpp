BOOST_AUTO_TEST_CASE(LRModelReload)
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
  SetInputParam("test", testX);

  // First solution
  mlpackMain();

  // Get the output model obtained from training.
  LogisticRegression<>* model =
      CLI::GetParam<LogisticRegression<>*>("output_model");
  // Get the output.
  const arma::Row<size_t> testY1 =
      std::move(CLI::GetParam<arma::Row<size_t>>("output"));

  // Reset the data passed.
  CLI::GetSingleton().Parameters()["training"].wasPassed = false;
  CLI::GetSingleton().Parameters()["labels"].wasPassed = false;
  CLI::GetSingleton().Parameters()["test"].wasPassed = false;

  SetInputParam("input_model", model);
  SetInputParam("test", std::move(testX));

  // Second solution.
  mlpackMain();

  // Get the output.
  const arma::Row<size_t> &testY2 =
      CLI::GetParam<arma::Row<size_t>>("output");

  // Both solutions must be equal.
  BOOST_REQUIRE_EQUAL_COLLECTIONS(testY1.begin(), testY1.end(),
                                  testY2.begin(), testY2.end());
}