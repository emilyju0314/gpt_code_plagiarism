void SampleIterator::MapSampleFeatures(const IntFeatureMap &feature_map) {
  for (Begin(); !AtEnd(); Next()) {
    TrainingSample *sample = MutableSample();
    MapFeatures(*sample, feature_map);
  }
}