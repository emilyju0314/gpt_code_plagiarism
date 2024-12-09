BOOST_AUTO_TEST_CASE(AdaBoostWithoutLabelTest)
{
  // Train adaboost without providing labels.
  arma::mat trainData;
  if (!data::Load("trainSet.csv", trainData))
    BOOST_FAIL("Unable to load train dataset trainSet.csv!");

  // Give labels.
  arma::Row<size_t> labels(trainData.n_cols);
  for (size_t i = 0; i < trainData.n_cols; ++i)
    labels[i] = trainData(trainData.n_rows - 1, i);

  arma::mat testData;
  if (!data::Load("testSet.csv", testData))
    BOOST_FAIL("Unable to load test dataset testSet.csv!");

  // Delete the last row containing labels from test dataset.
  testData.shed_row(testData.n_rows - 1);

  SetInputParam("training", trainData);

  SetInputParam("test", testData);

  mlpackMain();

  CLI::GetSingleton().Parameters()["training"].wasPassed = false;
  CLI::GetSingleton().Parameters()["test"].wasPassed = false;

  arma::Row<size_t> output;
  output = std::move(CLI::GetParam<arma::Row<size_t>>("output"));

  bindings::tests::CleanMemory();

  trainData.shed_row(trainData.n_rows - 1);

  // Now train Adaboost with labels provided.
  SetInputParam("training", std::move(trainData));
  SetInputParam("test", std::move(testData));
  SetInputParam("labels", std::move(labels));

  mlpackMain();

  // Check that initial output and final output matrix are same.
  CheckMatrices(output, CLI::GetParam<arma::Row<size_t>>("output"));
}