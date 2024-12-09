BOOST_AUTO_TEST_CASE(MulticlassClassificationMetricsTest)
{
  // Using the same data for training and testing.
  arma::mat data = arma::linspace<arma::rowvec>(1.0, 12.0, 12);

  // Labels that will be considered as "ground truth".
  arma::Row<size_t> labels("0 1  0 1  2 2 1 2  3 3 3 3");

  // These labels should be predicted in response to the data since we use them
  // for training.
  arma::Row<size_t> predictedLabels("0 0  1 1  2 2 2 2  3 3 3 3");
  size_t numClasses = 4;

  NaiveBayesClassifier<> nb(data, predictedLabels, numClasses);

  // Assert that the Naive Bayes model really predicts the labels above in
  // response to the data.
  BOOST_REQUIRE_CLOSE(Accuracy::Evaluate(nb, data, predictedLabels), 1.0, 1e-5);

  double microaveragedPrecision = double(1 + 1 + 3 + 4) / 12;
  BOOST_REQUIRE_CLOSE(Precision<Micro>::Evaluate(nb, data, labels),
      microaveragedPrecision, 1e-5);

  double microaveragedRecall = double(1 + 1 + 3 + 4) / 12;
  BOOST_REQUIRE_CLOSE(Recall<Micro>::Evaluate(nb, data, labels),
      microaveragedRecall, 1e-5);

  double microaveragedF1 = 2 * microaveragedPrecision * microaveragedRecall /
    (microaveragedPrecision + microaveragedRecall);
  BOOST_REQUIRE_CLOSE(F1<Micro>::Evaluate(nb, data, labels),
      microaveragedF1, 1e-5);

  double macroaveragedPrecision = (0.5 + 0.5 + 0.75 + 1.0) / 4;
  BOOST_REQUIRE_CLOSE(Precision<Macro>::Evaluate(nb, data, labels),
      macroaveragedPrecision, 1e-5);

  double macroaveragedRecall = (0.5 + 1.0 / 3 + 1.0 + 1.0) / 4;
  BOOST_REQUIRE_CLOSE(Recall<Macro>::Evaluate(nb, data, labels),
      macroaveragedRecall, 1e-5);

  double macroaveragedF1 = (2 * 0.5 * 0.5 / (0.5 + 0.5) +
      2 * 0.5 * (1.0 / 3) / (0.5 + (1.0 / 3)) + 2 * 0.75 * 1.0 / (0.75 + 1.0) +
      2 * 1.0 * 1.0 / (1.0 + 1.0)) / 4;
  BOOST_REQUIRE_CLOSE(F1<Macro>::Evaluate(nb, data, labels),
      macroaveragedF1, 1e-5);
}