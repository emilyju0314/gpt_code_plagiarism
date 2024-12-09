BOOST_AUTO_TEST_CASE(WeakLearnerErrorVertebralColumn_DS)
{
  arma::mat inputData;
  if (!data::Load("vc2.csv", inputData))
    BOOST_FAIL("Cannot load test dataset vc2.csv!");

  arma::Mat<size_t> labels;
  if (!data::Load("vc2_labels.txt", labels))
    BOOST_FAIL("Cannot load labels for vc2_labels.txt");

  // Define your own weak learner, decision stumps in this case.
  const size_t numClasses = 3;
  const size_t inpBucketSize = 6;
  arma::Row<size_t> dsPrediction(labels.n_cols);

  DecisionStump<> ds(inputData, labels.row(0), numClasses, inpBucketSize);
  ds.Classify(inputData, dsPrediction);

  size_t countWeakLearnerError = 0;
  for (size_t i = 0; i < labels.n_cols; i++)
    if (labels(i) != dsPrediction(i))
      countWeakLearnerError++;

  double weakLearnerErrorRate = (double) countWeakLearnerError / labels.n_cols;

  // Define parameters for AdaBoost.
  size_t iterations = 50;
  double tolerance = 1e-10;
  AdaBoost<DecisionStump<>> a(inputData, labels.row(0), numClasses, ds,
      iterations, tolerance);

  arma::Row<size_t> predictedLabels;
  a.Classify(inputData, predictedLabels);

  size_t countError = 0;
  for (size_t i = 0; i < labels.n_cols; i++)
    if (labels(i) != predictedLabels(i))
      countError++;
  double error = (double) countError / labels.n_cols;

  BOOST_REQUIRE_LE(error, weakLearnerErrorRate);
}