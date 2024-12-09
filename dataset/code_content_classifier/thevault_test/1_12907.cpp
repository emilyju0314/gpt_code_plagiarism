BOOST_AUTO_TEST_CASE(ClassifyTest_NONLINSEP)
{
  arma::mat inputData;
  if (!data::Load("train_nonlinsep.txt", inputData))
    BOOST_FAIL("Cannot load test dataset train_nonlinsep.txt!");

  arma::Mat<size_t> labels;
  if (!data::Load("train_labels_nonlinsep.txt", labels))
    BOOST_FAIL("Cannot load labels for train_labels_nonlinsep.txt");

  // Define your own weak learner; in this test decision stumps are used.
  const size_t numClasses = 2;
  const size_t inpBucketSize = 3;

  arma::mat testData;

  if (!data::Load("test_nonlinsep.txt", testData))
    BOOST_FAIL("Cannot load test dataset test_nonlinsep.txt!");

  arma::Mat<size_t> trueTestLabels;

  if (!data::Load("test_labels_nonlinsep.txt", trueTestLabels))
    BOOST_FAIL("Cannot load labels for test_labels_nonlinsep.txt");

  arma::Row<size_t> dsPrediction(labels.n_cols);

  DecisionStump<> ds(inputData, labels.row(0), numClasses, inpBucketSize);

  // Define parameters for AdaBoost.
  size_t iterations = 50;
  double tolerance = 1e-10;
  AdaBoost<DecisionStump<> > a(inputData, labels.row(0), numClasses, ds,
      iterations, tolerance);

  arma::Row<size_t> predictedLabels(testData.n_cols);
  a.Classify(testData, predictedLabels);

  size_t localError = 0;
  for (size_t i = 0; i < trueTestLabels.n_cols; i++)
    if (trueTestLabels(i) != predictedLabels(i))
      localError++;

  double lError = (double) localError / trueTestLabels.n_cols;
  BOOST_REQUIRE_LE(lError, 0.30);
}