int IntFeatureMap::FinalizeMapping(SampleIterator *it) {
  if (mapping_changed_) {
    feature_map_.CompleteMerges();
    compact_size_ = feature_map_.CompactSize();
#ifdef EXPERIMENT_ON
    it->MapSampleFeatures(*this);
#endif
    mapping_changed_ = false;
  }
  return compact_size_;
}