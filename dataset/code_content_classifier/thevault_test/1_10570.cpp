void IntFeatureMap::DebugMapFeatures(const std::vector<int> &map_features) const {
  for (int map_feature : map_features) {
    INT_FEATURE_STRUCT f = InverseMapFeature(map_feature);
    f.print();
  }
}