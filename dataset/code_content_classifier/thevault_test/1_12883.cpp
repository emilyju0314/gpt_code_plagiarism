BOOST_AUTO_TEST_CASE(KFoldCVWithDTTestUnevenBins)
{
  arma::mat data;
  arma::Row<size_t> labels;
  data::DatasetInfo datasetInfo;
  MockCategoricalData(data, labels, datasetInfo);

  size_t numClasses = 5;
  size_t minimumLeafSize = 5;

  KFoldCV<DecisionTree<InformationGain>, Accuracy> cv(7, data, datasetInfo,
      labels, numClasses);
  cv.Evaluate(minimumLeafSize);
  double accuracy = Accuracy::Evaluate(cv.Model(), data, labels);

  // This is a very loose tolerance, but we expect about the same as we would
  // from an individual decision tree training.
  BOOST_REQUIRE_GT(accuracy, 0.7);
}