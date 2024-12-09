BOOST_AUTO_TEST_CASE(AdaBoostOutputDimensionTest)
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

  size_t testSize = testData.n_cols;

  SetInputParam("training", std::move(trainData));
  SetInputParam("labels", std::move(labels));

  SetInputParam("test", std::move(testData));

  mlpackMain();

  // Check that number of predicted labels is equal to the input test points.
  BOOST_REQUIRE_EQUAL(CLI::GetParam<arma::Row<size_t>>("output").n_cols,
                      testSize);
  BOOST_REQUIRE_EQUAL(CLI::GetParam<arma::Row<size_t>>("output").n_rows, 1);
}