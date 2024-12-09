BOOST_AUTO_TEST_CASE(AdaBoostDiffTolTest)
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

  arma::Row<size_t> testLabels;
  if (!data::Load("vc2_test_labels.txt", testLabels))
    BOOST_FAIL("Unable to load labels for vc2__test_labels.txt");

  // tolerance = 0.001
  SetInputParam("training", trainData);
  SetInputParam("labels", labels);
  SetInputParam("tolerance", (double) 0.001);

  mlpackMain();

  // Calculate accuracy.
  arma::Row<size_t> output;
  CLI::GetParam<AdaBoostModel*>("output_model")->Classify(testData,
       output);

  size_t correct = arma::accu(output == testLabels);
  double accuracy1 = (double(correct) / double(testLabels.n_elem) * 100);

  bindings::tests::CleanMemory();

  // tolerance = 0.01
  SetInputParam("training", trainData);
  SetInputParam("labels", labels);
  SetInputParam("tolerance", (double) 0.01);

  mlpackMain();

  // Calculate accuracy.
  CLI::GetParam<AdaBoostModel*>("output_model")->Classify(testData,
       output);

  correct = arma::accu(output == testLabels);
  double accuracy2 = (double(correct) / double(testLabels.n_elem) * 100);

  bindings::tests::CleanMemory();

  // tolerance = 0.1
  SetInputParam("training", trainData);
  SetInputParam("labels", labels);
  SetInputParam("tolerance", (double) 0.1);

  mlpackMain();

  // Calculate accuracy.
  CLI::GetParam<AdaBoostModel*>("output_model")->Classify(testData,
       output);

  correct = arma::accu(output == testLabels);
  double accuracy3 = (double(correct) / double(testLabels.n_elem) * 100);

  BOOST_REQUIRE_LE(accuracy1, accuracy2);
  BOOST_REQUIRE_LE(accuracy2, accuracy3);
}