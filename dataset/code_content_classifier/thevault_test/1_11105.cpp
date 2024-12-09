CLUSTERER *SetUpForClustering(const FEATURE_DEFS_STRUCT &FeatureDefs, LABELEDLIST char_sample,
                              const char *program_feature_type) {
  uint16_t N;
  CLUSTERER *Clusterer;
  LIST FeatureList = nullptr;
  FEATURE_SET FeatureSet = nullptr;

  int32_t desc_index = ShortNameToFeatureType(FeatureDefs, program_feature_type);
  N = FeatureDefs.FeatureDesc[desc_index]->NumParams;
  Clusterer = MakeClusterer(N, FeatureDefs.FeatureDesc[desc_index]->ParamDesc);

  FeatureList = char_sample->List;
  uint32_t CharID = 0;
  std::vector<float> Sample;
  iterate(FeatureList) {
    FeatureSet = reinterpret_cast<FEATURE_SET>(FeatureList->first_node());
    for (int i = 0; i < FeatureSet->MaxNumFeatures; i++) {
      if (Sample.empty()) {
        Sample.resize(N);
      }
      for (int j = 0; j < N; j++) {
        Sample[j] = FeatureSet->Features[i]->Params[j];
      }
      MakeSample(Clusterer, &Sample[0], CharID);
    }
    CharID++;
  }
  return Clusterer;

}