BOOST_AUTO_TEST_CASE(KFoldCVAccuracyTest)
{
  // Making a 10-points dataset. The last point should be classified wrong when
  // it is tested separately.
  arma::mat data("0 1 2 3 100 101 102 103 104 5");
  arma::Row<size_t> labels("0 0 0 0 1 1 1 1 1 1");
  size_t numClasses = 2;

  // 10-fold cross-validation, no shuffling.
  KFoldCV<NaiveBayesClassifier<>, Accuracy> cv(10, data, labels, numClasses,
      false);

  // We should succeed in classifying separately the first nine samples, and
  // fail with the remaining one.
  double expectedAccuracy = (9 * 1.0 + 0.0) / 10;

  BOOST_REQUIRE_CLOSE(cv.Evaluate(), expectedAccuracy, 1e-5);

  // Assert we can access a trained model without the exception of
  // uninitialization.
  cv.Model();
}