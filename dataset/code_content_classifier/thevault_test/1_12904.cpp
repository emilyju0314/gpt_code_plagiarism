BOOST_AUTO_TEST_CASE(HammingLossBoundNonLinearSepData_DS)
{
  arma::mat inputData;
  if (!data::Load("train_nonlinsep.txt", inputData))
    BOOST_FAIL("Cannot load test dataset train_nonlinsep.txt!");

  arma::Mat<size_t> labels;
  if (!data::Load("train_labels_nonlinsep.txt", labels))
    BOOST_FAIL("Cannot load labels for train_labels_nonlinsep.txt");

  // Define your own weak learner, decision stumps in this case.
  const size_t numClasses = 2;
  const size_t inpBucketSize = 6;

  DecisionStump<> ds(inputData, labels.row(0), numClasses, inpBucketSize);

  // Define parameters for Adaboost.
  size_t iterations = 50;
  double tolerance = 1e-10;

  AdaBoost<DecisionStump<> > a(inputData, labels.row(0), numClasses, ds,
      iterations, tolerance);

  arma::Row<size_t> predictedLabels;
  a.Classify(inputData, predictedLabels);

  size_t countError = 0;
  for (size_t i = 0; i < labels.n_cols; i++)
    if (labels(i) != predictedLabels(i))
      countError++;
  double hammingLoss = (double) countError / labels.n_cols;

  BOOST_REQUIRE_LE(hammingLoss, a.ZtProduct());
}