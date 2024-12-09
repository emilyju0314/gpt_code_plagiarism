BOOST_AUTO_TEST_CASE(KFoldCVWithDTTest)
{
  arma::mat originalData;
  arma::Row<size_t> originalLabels;
  data::DatasetInfo datasetInfo;
  MockCategoricalData(originalData, originalLabels, datasetInfo);

  // Each fold will be filled with this dataset.
  arma::mat data = originalData.cols(0, 1199);
  arma::Row<size_t> labels = originalLabels.cols(0, 1199);
  arma::rowvec weights(data.n_cols, arma::fill::randu);

  arma::mat doubledData = arma::join_rows(data, data);
  arma::Row<size_t> doubledLabels = arma::join_rows(labels, labels);
  arma::rowvec doubledWeights = arma::join_rows(weights, weights);

  size_t numClasses = 5;
  size_t minimumLeafSize = 8;

  {
    KFoldCV<DecisionTree<InformationGain>, Accuracy> cv(2, doubledData,
        doubledLabels, numClasses, false);
    cv.Evaluate(minimumLeafSize);
    arma::Row<size_t> predictedLabels = PredictLabelsWithDT(data, data, labels,
        numClasses, minimumLeafSize);
    double accuracy = Accuracy::Evaluate(cv.Model(), data, predictedLabels);
    BOOST_REQUIRE_CLOSE(accuracy, 1.0, 1e-5);
  }
  {
    KFoldCV<DecisionTree<InformationGain>, Accuracy> cv(2, doubledData,
        datasetInfo, doubledLabels, numClasses, false);
    cv.Evaluate(minimumLeafSize);
    arma::Row<size_t> predictedLabels = PredictLabelsWithDT(data, data,
        datasetInfo, labels, numClasses, minimumLeafSize);
    double accuracy = Accuracy::Evaluate(cv.Model(), data, predictedLabels);
    BOOST_REQUIRE_CLOSE(accuracy, 1.0, 1e-5);
  }
  {
    KFoldCV<DecisionTree<InformationGain>, Accuracy> cv(2, doubledData,
        doubledLabels, numClasses, doubledWeights, false);
    cv.Evaluate(minimumLeafSize);
    arma::Row<size_t> predictedLabels = PredictLabelsWithDT(data, data, labels,
        numClasses, weights, minimumLeafSize);
    double accuracy = Accuracy::Evaluate(cv.Model(), data, predictedLabels);
    BOOST_REQUIRE_CLOSE(accuracy, 1.0, 1e-5);
  }
  {
    KFoldCV<DecisionTree<InformationGain>, Accuracy> cv(2, doubledData,
        datasetInfo, doubledLabels, numClasses, doubledWeights, false);
    cv.Evaluate(minimumLeafSize);
    arma::Row<size_t> predictedLabels = PredictLabelsWithDT(data, data,
        datasetInfo, labels, numClasses, weights, minimumLeafSize);
    double accuracy = Accuracy::Evaluate(cv.Model(), data, predictedLabels);
    BOOST_REQUIRE_CLOSE(accuracy, 1.0, 1e-5);
  }
}