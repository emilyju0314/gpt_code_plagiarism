BOOST_AUTO_TEST_CASE(OneClass)
{
  const size_t numClasses = 2;
  const size_t inpBucketSize = 6;

  mat trainingData;
  trainingData << 2.4 << 3.8 << 3.8 << endr
               << 1   << 1   << 2   << endr
               << 1.3 << 1.9 << 1.3 << endr;

  // No need to normalize labels here.
  Mat<size_t> labelsIn;
  labelsIn << 1 << 1 << 1;

  mat testingData;
  testingData << 2.4 << 2.5 << 2.6;

  DecisionStump<> ds(trainingData, labelsIn.row(0), numClasses, inpBucketSize);

  Row<size_t> predictedLabels;
  ds.Classify(testingData, predictedLabels);

  for (size_t i = 0; i < predictedLabels.size(); i++)
    BOOST_CHECK_EQUAL(predictedLabels(i), 1);
}