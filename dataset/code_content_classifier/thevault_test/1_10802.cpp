TrainingSample *TrainingSample::Copy() const {
  auto *sample = new TrainingSample;
  sample->class_id_ = class_id_;
  sample->font_id_ = font_id_;
  sample->weight_ = weight_;
  sample->sample_index_ = sample_index_;
  sample->num_features_ = num_features_;
  if (num_features_ > 0) {
    sample->features_ = new INT_FEATURE_STRUCT[num_features_];
    memcpy(sample->features_, features_, num_features_ * sizeof(features_[0]));
  }
  sample->num_micro_features_ = num_micro_features_;
  if (num_micro_features_ > 0) {
    sample->micro_features_ = new MicroFeature[num_micro_features_];
    memcpy(sample->micro_features_, micro_features_,
           num_micro_features_ * sizeof(micro_features_[0]));
  }
  memcpy(sample->cn_feature_, cn_feature_, sizeof(*cn_feature_) * kNumCNParams);
  memcpy(sample->geo_feature_, geo_feature_, sizeof(*geo_feature_) * GeoCount);
  return sample;
}