CHAR_DESC_STRUCT *ReadCharDescription(const FEATURE_DEFS_STRUCT &FeatureDefs, FILE *File) {
  int NumSetsToRead;
  char ShortName[FEAT_NAME_SIZE];
  int Type;

  ASSERT_HOST(tfscanf(File, "%d", &NumSetsToRead) == 1);
  ASSERT_HOST(NumSetsToRead >= 0);
  ASSERT_HOST(NumSetsToRead <= FeatureDefs.NumFeatureTypes);

  auto CharDesc = new CHAR_DESC_STRUCT(FeatureDefs);
  for (; NumSetsToRead > 0; NumSetsToRead--) {
    tfscanf(File, "%s", ShortName);
    Type = ShortNameToFeatureType(FeatureDefs, ShortName);
    CharDesc->FeatureSets[Type] = ReadFeatureSet(File, FeatureDefs.FeatureDesc[Type]);
  }
  return CharDesc;
}