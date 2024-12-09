bool TrainingSample::DeSerialize(bool swap, FILE *fp) {
  if (fread(&class_id_, sizeof(class_id_), 1, fp) != 1) {
    return false;
  }
  if (fread(&font_id_, sizeof(font_id_), 1, fp) != 1) {
    return false;
  }
  if (fread(&page_num_, sizeof(page_num_), 1, fp) != 1) {
    return false;
  }
  if (!bounding_box_.DeSerialize(swap, fp)) {
    return false;
  }
  if (fread(&num_features_, sizeof(num_features_), 1, fp) != 1) {
    return false;
  }
  if (fread(&num_micro_features_, sizeof(num_micro_features_), 1, fp) != 1) {
    return false;
  }
  if (fread(&outline_length_, sizeof(outline_length_), 1, fp) != 1) {
    return false;
  }
  if (swap) {
    ReverseN(&class_id_, sizeof(class_id_));
    ReverseN(&num_features_, sizeof(num_features_));
    ReverseN(&num_micro_features_, sizeof(num_micro_features_));
    ReverseN(&outline_length_, sizeof(outline_length_));
  }
  // Arbitrarily limit the number of elements to protect against bad data.
  if (num_features_ > UINT16_MAX) {
    return false;
  }
  if (num_micro_features_ > UINT16_MAX) {
    return false;
  }
  delete[] features_;
  features_ = new INT_FEATURE_STRUCT[num_features_];
  if (fread(features_, sizeof(*features_), num_features_, fp) != num_features_) {
    return false;
  }
  delete[] micro_features_;
  micro_features_ = new MicroFeature[num_micro_features_];
  if (fread(micro_features_, sizeof(*micro_features_), num_micro_features_, fp) !=
      num_micro_features_) {
    return false;
  }
  if (fread(cn_feature_, sizeof(*cn_feature_), kNumCNParams, fp) != kNumCNParams) {
    return false;
  }
  if (fread(geo_feature_, sizeof(*geo_feature_), GeoCount, fp) != GeoCount) {
    return false;
  }
  return true;
}