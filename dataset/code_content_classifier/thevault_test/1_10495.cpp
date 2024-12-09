static void MapFeatures(TrainingSample &s, const IntFeatureMap &feature_map) {
  std::vector<int> indexed_features;
  feature_map.feature_space().IndexAndSortFeatures(s.features(), s.num_features(),
                                                   &indexed_features);
  feature_map.MapIndexedFeatures(indexed_features, &s.mapped_features_);
  s.features_are_indexed_ = false;
  s.features_are_mapped_ = true;
}