void FreeTrainingSamples(LIST CharList) {
  LABELEDLIST char_sample;
  FEATURE_SET FeatureSet;
  LIST FeatureList;

  LIST nodes = CharList;
  iterate(CharList) { /* iterate through all of the fonts */
    char_sample = reinterpret_cast<LABELEDLIST>(CharList->first_node());
    FeatureList = char_sample->List;
    iterate(FeatureList) { /* iterate through all of the classes */
      FeatureSet = reinterpret_cast<FEATURE_SET>(FeatureList->first_node());
      delete FeatureSet;
    }
    FreeLabeledList(char_sample);
  }
  destroy(nodes);
}