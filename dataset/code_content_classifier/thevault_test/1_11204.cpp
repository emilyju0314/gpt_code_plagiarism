void WriteCharDescription(const FEATURE_DEFS_STRUCT &FeatureDefs, CHAR_DESC_STRUCT *CharDesc, std::string &str) {
  int NumSetsToWrite = 0;

  for (size_t Type = 0; Type < CharDesc->NumFeatureSets; Type++) {
    if (CharDesc->FeatureSets[Type]) {
      NumSetsToWrite++;
    }
  }

  str += " " + std::to_string(NumSetsToWrite);
  str += "\n";
  for (size_t Type = 0; Type < CharDesc->NumFeatureSets; Type++) {
    if (CharDesc->FeatureSets[Type]) {
      str += FeatureDefs.FeatureDesc[Type]->ShortName;
      str += " ";
      WriteFeatureSet(CharDesc->FeatureSets[Type], str);
    }
  }
}