BOOST_AUTO_TEST_CASE(SupportsWeightsTest)
{
  static_assert(MetaInfoExtractor<LinearRegression>::SupportsWeights,
      "Value should be true");
  static_assert(MetaInfoExtractor<DecisionTree<>>::SupportsWeights,
      "Value should be true");
  static_assert(MetaInfoExtractor<DecisionTree<>, arma::mat, arma::urowvec,
      arma::Row<float>>::SupportsWeights, "Value should be true");

  static_assert(!MetaInfoExtractor<LARS>::SupportsWeights,
      "Value should be false");
  static_assert(!MetaInfoExtractor<LogisticRegression<>>::SupportsWeights,
      "Value should be false");
}