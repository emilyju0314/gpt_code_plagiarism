BOOST_AUTO_TEST_CASE(ClassifyTest_IRIS)
{
  arma::mat inputData;
  if (!data::Load("iris_train.csv", inputData))
    BOOST_FAIL("Cannot load test dataset iris_train.csv!");

  arma::Mat<size_t> labels;
  if (!data::Load("iris_train_labels.csv", labels))
    BOOST_FAIL("Cannot load labels for iris_train_labels.csv");
  const size_t numClasses = max(labels.row(0)) + 1;

  // Define your own weak learner, perceptron in this case.
  // Run the perceptron for perceptronIter iterations.
  size_t perceptronIter = 800;

  Perceptron<> p(inputData, labels.row(0), numClasses, perceptronIter);

  // Define parameters for AdaBoost.
  size_t iterations = 50;
  double tolerance = 1e-10;
  AdaBoost<> a(inputData, labels.row(0), numClasses, p, iterations, tolerance);

  arma::mat testData;
  if (!data::Load("iris_test.csv", testData))
    BOOST_FAIL("Cannot load test dataset iris_test.csv!");

  arma::Row<size_t> predictedLabels(testData.n_cols);

  a.Classify(testData, predictedLabels);

  arma::Mat<size_t> trueTestLabels;
  if (!data::Load("iris_test_labels.csv", trueTestLabels))
    BOOST_FAIL("Cannot load test dataset iris_test_labels.csv!");

  size_t localError = 0;
  for (size_t i = 0; i < trueTestLabels.n_cols; i++)
    if (trueTestLabels(i) != predictedLabels(i))
      localError++;
  double lError = (double) localError / labels.n_cols;
  BOOST_REQUIRE_LE(lError, 0.30);
}