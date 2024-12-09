BOOST_AUTO_TEST_CASE(LRResponsesRepresentationTest)
{
  arma::mat trainX1({{1.0, 2.0, 3.0}, {1.0, 4.0, 9.0}, {0, 1, 1}});
  arma::mat testX({{4.0, 5.0}, {1.0, 6.0}});

  SetInputParam("training", std::move(trainX1));
  SetInputParam("test", testX);

  // The first solution.
  mlpackMain();

  // Get the output.
  const arma::Row<size_t> testY1 =
      std::move(CLI::GetParam<arma::Row<size_t>>("output"));

  // Reset the settings.
  bindings::tests::CleanMemory();
  CLI::ClearSettings();
  CLI::RestoreSettings(testName);

  // Now train by providing labels as extra parameter.
  arma::mat trainX2({{1.0, 2.0, 3.0}, {1.0, 4.0, 9.0}});
  arma::Row<size_t> trainY2({0, 1, 1});

  SetInputParam("training", std::move(trainX2));
  SetInputParam("labels", std::move(trainY2));
  SetInputParam("test", std::move(testX));

  // The second solution.
  mlpackMain();

  // get the output
  const arma::Row<size_t> &testY2 =
      CLI::GetParam<arma::Row<size_t>>("output");

  // Both solutions should be equal.
  BOOST_REQUIRE_EQUAL_COLLECTIONS(testY1.begin(), testY1.end(),
                                  testY2.begin(), testY2.end());
}