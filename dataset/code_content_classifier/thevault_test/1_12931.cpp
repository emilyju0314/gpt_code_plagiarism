BOOST_AUTO_TEST_CASE(IntTest)
{
  // Train on a dataset and make sure something kind of makes sense.
  imat trainingData;
  trainingData << -7 << -6 << -5 << -4 << -3 << -2 << -1 << 0 << 1
               << 2  << 3  << 4  << 5  << 6  << 7  << 8  << 9 << 10;

  // No need to normalize labels here.
  Mat<size_t> labelsIn;
  labelsIn << 0 << 0 << 0 << 0 << 1 << 1 << 0 << 0
           << 1 << 1 << 1 << 2 << 1 << 2 << 2 << 2 << 2 << 2;

  DecisionStump<arma::imat> ds(trainingData, labelsIn.row(0), 4, 3);

  imat testingData;
  testingData << -6 << -6 << -2 << -1 << 3 << 5 << 7 << 9;

  arma::Row<size_t> predictedLabels;
  ds.Classify(testingData, predictedLabels);

  BOOST_CHECK_EQUAL(predictedLabels(0, 0), 0);
  BOOST_CHECK_EQUAL(predictedLabels(0, 1), 0);
  BOOST_CHECK_EQUAL(predictedLabels(0, 2), 1);
  BOOST_CHECK_EQUAL(predictedLabels(0, 3), 1);
  BOOST_CHECK_EQUAL(predictedLabels(0, 4), 1);
  BOOST_CHECK_EQUAL(predictedLabels(0, 5), 1);
  BOOST_CHECK_EQUAL(predictedLabels(0, 6), 2);
  BOOST_CHECK_EQUAL(predictedLabels(0, 7), 2);
}