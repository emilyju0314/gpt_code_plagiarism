BOOST_AUTO_TEST_CASE(TrainTest)
{
  // First train on the iris dataset.
  arma::mat inputData;
  if (!data::Load("iris_train.csv", inputData))
    BOOST_FAIL("Cannot load test dataset iris_train.csv!");

  arma::Mat<size_t> labels;
  if (!data::Load("iris_train_labels.csv", labels))
    BOOST_FAIL("Cannot load labels for iris_train_labels.csv");

  const size_t numClasses = max(labels.row(0)) + 1;

  size_t perceptronIter = 800;
  Perceptron<> p(inputData, labels.row(0), numClasses, perceptronIter);

  // Now train AdaBoost.
  size_t iterations = 50;
  double tolerance = 1e-10;
  AdaBoost<> a(inputData, labels.row(0), numClasses, p, iterations, tolerance);

  // Now load another dataset...
  if (!data::Load("vc2.csv", inputData))
    BOOST_FAIL("Cannot load test dataset vc2.csv!");
  if (!data::Load("vc2_labels.txt", labels))
    BOOST_FAIL("Cannot load labels for vc2_labels.txt");

  const size_t newNumClasses = max(labels.row(0)) + 1;

  Perceptron<> p2(inputData, labels.row(0), newNumClasses, perceptronIter);

  a.Train(inputData, labels.row(0), newNumClasses, p2, iterations, tolerance);

  // Load test set to see if it trained on vc2 correctly.
  arma::mat testData;
  if (!data::Load("vc2_test.csv", testData))
    BOOST_FAIL("Cannot load test dataset vc2_test.csv!");

  arma::Mat<size_t> trueTestLabels;
  if (!data::Load("vc2_test_labels.txt", trueTestLabels))
    BOOST_FAIL("Cannot load labels for vc2_test_labels.txt");

  // Define parameters for AdaBoost.
  arma::Row<size_t> predictedLabels(testData.n_cols);
  a.Classify(testData, predictedLabels);

  int localError = 0;
  for (size_t i = 0; i < trueTestLabels.n_cols; i++)
    if (trueTestLabels(i) != predictedLabels(i))
      localError++;

  double lError = (double) localError / trueTestLabels.n_cols;

  BOOST_REQUIRE_LE(lError, 0.30);
}