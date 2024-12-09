BOOST_AUTO_TEST_CASE(SimpleCVWithDTTest)
{
  arma::mat data;
  arma::Row<size_t> labels;
  data::DatasetInfo datasetInfo;
  MockCategoricalData(data, labels, datasetInfo);

  arma::mat trainingData = data.cols(0, 1999);
  arma::mat testData = data.cols(2000, 3999);
  arma::Row<size_t> trainingLabels = labels.subvec(0, 1999);

  arma::rowvec weights(4000, arma::fill::randu);

  size_t numClasses = 5;
  size_t minimumLeafSize = 8;

  {
    arma::Row<size_t> predictedLabels = PredictLabelsWithDT(testData,
        trainingData, trainingLabels, numClasses, minimumLeafSize);
    SimpleCV<DecisionTree<InformationGain>, Accuracy> cv(0.5, data,
        arma::join_rows(trainingLabels, predictedLabels), numClasses);
    BOOST_REQUIRE_CLOSE(cv.Evaluate(minimumLeafSize), 1.0, 1e-5);
  }
  {
    arma::Row<size_t> predictedLabels = PredictLabelsWithDT(testData,
        trainingData, datasetInfo, trainingLabels, numClasses, minimumLeafSize);
    SimpleCV<DecisionTree<InformationGain>, Accuracy> cv(0.5, data, datasetInfo,
        arma::join_rows(trainingLabels, predictedLabels), numClasses);
    BOOST_REQUIRE_CLOSE(cv.Evaluate(minimumLeafSize), 1.0, 1e-5);
  }
  {
    arma::Row<size_t> predictedLabels = PredictLabelsWithDT(testData,
        trainingData, trainingLabels, numClasses, weights, minimumLeafSize);
    SimpleCV<DecisionTree<InformationGain>, Accuracy> cv(0.5, data,
        arma::join_rows(trainingLabels, predictedLabels), numClasses, weights);
    BOOST_REQUIRE_CLOSE(cv.Evaluate(minimumLeafSize), 1.0, 1e-5);
  }
  {
    arma::Row<size_t> predictedLabels = PredictLabelsWithDT(testData,
        trainingData, datasetInfo, trainingLabels, numClasses, weights,
        minimumLeafSize);
    SimpleCV<DecisionTree<InformationGain>, Accuracy> cv(0.5, data, datasetInfo,
        arma::join_rows(trainingLabels, predictedLabels), numClasses, weights);
    BOOST_REQUIRE_CLOSE(cv.Evaluate(minimumLeafSize), 1.0, 1e-5);
  }
}