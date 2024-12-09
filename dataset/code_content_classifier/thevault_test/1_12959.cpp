BOOST_AUTO_TEST_CASE(LRDecisionBoundaryTest)
{
  constexpr int N = 10;
  constexpr int D = 3;
  constexpr int M = 15;

  arma::mat trainX = arma::randu<arma::mat>(D, N);
  arma::Row<size_t> trainY;

  // 10 responses.
  trainY << 1 << 0 << 0 << 1 << 0 << 1 << 0 << 1 << 0 << 1 << arma::endr;

  arma::mat testX = arma::randu<arma::mat>(D, M);

  SetInputParam("training", trainX);
  SetInputParam("labels", trainY);
  SetInputParam("decision_boundary", double(1));
  SetInputParam("test", testX);

  // First solution.
  mlpackMain();

  // Get the output after first training.
  const arma::Row<size_t> output1 = CLI::GetParam<arma::Row<size_t>>("output");

  // Reset the settings.
  bindings::tests::CleanMemory();
  CLI::ClearSettings();
  CLI::RestoreSettings(testName);

  SetInputParam("training", trainX);
  SetInputParam("labels", trainY);
  SetInputParam("decision_boundary", double(0));
  SetInputParam("test", testX);

  // Second solution.
  mlpackMain();

  // Get the output after second training.
  const arma::Row<size_t> &output2 = CLI::GetParam<arma::Row<size_t>>("output");

  // Check that the output changed when the decision boundary moved.
  BOOST_REQUIRE_GT(arma::accu(output1 != output2), 0);
}