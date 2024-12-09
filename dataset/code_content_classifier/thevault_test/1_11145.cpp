void Classify::LearnBlob(const std::string &fontname, TBLOB *blob, const DENORM &cn_denorm,
                         const INT_FX_RESULT_STRUCT &fx_info, const char *blob_text) {
  std::unique_ptr<CHAR_DESC_STRUCT> CharDesc(new CHAR_DESC_STRUCT(feature_defs_));
  CharDesc->FeatureSets[0] = ExtractMicros(blob, cn_denorm);
  CharDesc->FeatureSets[1] = ExtractCharNormFeatures(fx_info);
  CharDesc->FeatureSets[2] = ExtractIntCNFeatures(*blob, fx_info);
  CharDesc->FeatureSets[3] = ExtractIntGeoFeatures(*blob, fx_info);

  if (ValidCharDescription(feature_defs_, CharDesc.get())) {
    // Label the features with a class name and font name.
    tr_file_data_ += "\n";
    tr_file_data_ += fontname;
    tr_file_data_ += " ";
    tr_file_data_ += blob_text;
    tr_file_data_ += "\n";

    // write micro-features to file and clean up
    WriteCharDescription(feature_defs_, CharDesc.get(), tr_file_data_);
  } else {
    tprintf("Blob learned was invalid!\n");
  }
}