BOOST_AUTO_TEST_CASE(HammingLossBoundIris)
{
  arma::mat inputData;

  if (!data::Load("iris.csv", inputData))
    BOOST_FAIL("Cannot load test dataset iris.csv!");

  arma::Mat<size_t> labels;
  if (!data::Load("iris_labels.txt", labels))
    BOOST_FAIL("Cannot load labels for iris iris_labels.txt");

  const size_t numClasses = max(labels.row(0)) + 1;

  // Define your own weak learner, perceptron in this case.
  // Run the perceptron for perceptronIter iterations.
  int perceptronIter = 400;

  Perceptron<> p(inputData, labels.row(0), numClasses, perceptronIter);

  // Define parameters for AdaBoost.
  size_t iterations = 100;
  double tolerance = 1e-10;
  AdaBoost<> a(inputData, labels.row(0), numClasses, p, iterations, tolerance);

  arma::Row<size_t> predictedLabels;
  a.Classify(inputData, predictedLabels);

  size_t countError = 0;
  for (size_t i = 0; i < labels.n_cols; i++)
    if (labels(i) != predictedLabels(i))
      countError++;
  double hammingLoss = (double) countError / labels.n_cols;

  BOOST_REQUIRE_LE(hammingLoss, a.ZtProduct());
}