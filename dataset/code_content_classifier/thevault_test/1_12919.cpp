BOOST_AUTO_TEST_CASE(AdaBoostDiffWeakLearnerOutputTest)
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

  SetInputParam("training", trainData);
  SetInputParam("labels", labels);
  SetInputParam("test", testData);

  mlpackMain();

  arma::Row<size_t> output;
  output = std::move(CLI::GetParam<arma::Row<size_t>>("output"));

  bindings::tests::CleanMemory();

  CLI::GetSingleton().Parameters()["training"].wasPassed = false;
  CLI::GetSingleton().Parameters()["labels"].wasPassed = false;
  CLI::GetSingleton().Parameters()["test"].wasPassed = false;

  SetInputParam("training", trainData);
  SetInputParam("labels", labels);
  SetInputParam("test", testData);
  SetInputParam("weak_learner", std::string("perceptron"));

  mlpackMain();

  arma::Row<size_t> outputPerceptron;
  outputPerceptron = std::move(CLI::GetParam<arma::Row<size_t>>("output"));

  BOOST_REQUIRE_GT(arma::accu(output != outputPerceptron), 1);
}