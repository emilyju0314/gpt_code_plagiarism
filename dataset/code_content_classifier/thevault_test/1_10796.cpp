bool TrainingSample::Serialize(FILE *fp) const {
  if (fwrite(&class_id_, sizeof(class_id_), 1, fp) != 1) {
    return false;
  }
  if (fwrite(&font_id_, sizeof(font_id_), 1, fp) != 1) {
    return false;
  }
  if (fwrite(&page_num_, sizeof(page_num_), 1, fp) != 1) {
    return false;
  }
  if (!bounding_box_.Serialize(fp)) {
    return false;
  }
  if (fwrite(&num_features_, sizeof(num_features_), 1, fp) != 1) {
    return false;
  }
  if (fwrite(&num_micro_features_, sizeof(num_micro_features_), 1, fp) != 1) {
    return false;
  }
  if (fwrite(&outline_length_, sizeof(outline_length_), 1, fp) != 1) {
    return false;
  }
  if (fwrite(features_, sizeof(*features_), num_features_, fp) != num_features_) {
    return false;
  }
  if (fwrite(micro_features_, sizeof(*micro_features_), num_micro_features_, fp) !=
      num_micro_features_) {
    return false;
  }
  if (fwrite(cn_feature_, sizeof(*cn_feature_), kNumCNParams, fp) != kNumCNParams) {
    return false;
  }
  if (fwrite(geo_feature_, sizeof(*geo_feature_), GeoCount, fp) != GeoCount) {
    return false;
  }
  return true;
}