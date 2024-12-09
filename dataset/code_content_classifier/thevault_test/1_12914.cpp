BOOST_AUTO_TEST_CASE(AdaBoostModelReuseTest)
{
  arma::mat trainData;
  if (!data::Load("vc2.csv", trainData))
    BOOST_FAIL("Unable to load train dataset vc2.csv!");

  arma::Row<size_t> labels;
  if (!data::Load("vc2_labels.txt", labels))
    BOOST_FAIL("Unable to load label dataset vc2_labels.txt!");

  arma::mat testData;
  if (!data::Load("vc2_test.csv", testData))
    BOOST_FAIL("Unable to load test dataset vc2.csv!");

  SetInputParam("training", std::move(trainData));
  SetInputParam("labels", std::move(labels));

  SetInputParam("test", testData);

  mlpackMain();

  arma::Row<size_t> output;
  output = std::move(CLI::GetParam<arma::Row<size_t>>("output"));

  CLI::GetSingleton().Parameters()["training"].wasPassed = false;
  CLI::GetSingleton().Parameters()["labels"].wasPassed = false;
  CLI::GetSingleton().Parameters()["test"].wasPassed = false;

  SetInputParam("test", std::move(testData));
  SetInputParam("input_model",
                CLI::GetParam<AdaBoostModel*>("output_model"));

  mlpackMain();

  // Check that initial output and output using saved model are same.
  CheckMatrices(output, CLI::GetParam<arma::Row<size_t>>("output"));
}