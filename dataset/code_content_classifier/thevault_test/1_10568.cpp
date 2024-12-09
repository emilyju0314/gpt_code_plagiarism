int IntFeatureMap::FindNZFeatureMapping(SampleIterator *it) {
  feature_map_.Init(feature_space_.Size(), false);
  int total_samples = 0;
  for (it->Begin(); !it->AtEnd(); it->Next()) {
    const TrainingSample &sample = it->GetSample();
    std::vector<int> features;
    feature_space_.IndexAndSortFeatures(sample.features(), sample.num_features(), &features);
    int num_features = features.size();
    for (int f = 0; f < num_features; ++f)
      feature_map_.SetMap(features[f], true);
    ++total_samples;
  }
  feature_map_.Setup();
  compact_size_ = feature_map_.CompactSize();
  mapping_changed_ = true;
  FinalizeMapping(it);
  tprintf("%d non-zero features found in %d samples\n", compact_size_, total_samples);
  return compact_size_;
}