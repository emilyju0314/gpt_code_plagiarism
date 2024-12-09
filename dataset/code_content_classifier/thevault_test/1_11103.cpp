void ReadTrainingSamples(const FEATURE_DEFS_STRUCT &feature_definitions, const char *feature_name,
                         int max_samples, UNICHARSET *unicharset, FILE *file,
                         LIST *training_samples) {
  char buffer[2048];
  char unichar[UNICHAR_LEN + 1];
  LABELEDLIST char_sample;
  FEATURE_SET feature_samples;
  uint32_t feature_type = ShortNameToFeatureType(feature_definitions, feature_name);

  // Zero out the font_sample_count for all the classes.
  LIST it = *training_samples;
  iterate(it) {
    char_sample = reinterpret_cast<LABELEDLIST>(it->first_node());
    char_sample->font_sample_count = 0;
  }

  while (fgets(buffer, 2048, file) != nullptr) {
    if (buffer[0] == '\n') {
      continue;
    }

    sscanf(buffer, "%*s %s", unichar);
    if (unicharset != nullptr && !unicharset->contains_unichar(unichar)) {
      unicharset->unichar_insert(unichar);
      if (unicharset->size() > MAX_NUM_CLASSES) {
        tprintf(
            "Error: Size of unicharset in training is "
            "greater than MAX_NUM_CLASSES\n");
        exit(1);
      }
    }
    char_sample = FindList(*training_samples, unichar);
    if (char_sample == nullptr) {
      char_sample = new LABELEDLISTNODE(unichar);
      *training_samples = push(*training_samples, char_sample);
    }
    auto char_desc = ReadCharDescription(feature_definitions, file);
    feature_samples = char_desc->FeatureSets[feature_type];
    if (char_sample->font_sample_count < max_samples || max_samples <= 0) {
      char_sample->List = push(char_sample->List, feature_samples);
      char_sample->SampleCount++;
      char_sample->font_sample_count++;
    } else {
      delete feature_samples;
    }
    for (size_t i = 0; i < char_desc->NumFeatureSets; i++) {
      if (feature_type != i) {
        delete char_desc->FeatureSets[i];
      }
    }
    delete char_desc;
  }
}