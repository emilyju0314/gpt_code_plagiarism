std::unique_ptr<MasterTrainer> LoadTrainingData(const char *const *filelist, bool replication,
                                                ShapeTable **shape_table, std::string &file_prefix) {
  InitFeatureDefs(&feature_defs);
  InitIntegerFX();
  file_prefix = "";
  if (!FLAGS_D.empty()) {
    file_prefix += FLAGS_D.c_str();
    file_prefix += "/";
  }
  // If we are shape clustering (nullptr shape_table) or we successfully load
  // a shape_table written by a previous shape clustering, then
  // shape_analysis will be true, meaning that the MasterTrainer will replace
  // some members of the unicharset with their fragments.
  bool shape_analysis = false;
  if (shape_table != nullptr) {
    *shape_table = LoadShapeTable(file_prefix);
    if (*shape_table != nullptr) {
      shape_analysis = true;
    }
  } else {
    shape_analysis = true;
  }
  auto trainer = std::make_unique<MasterTrainer>(NM_CHAR_ANISOTROPIC, shape_analysis, replication,
                                                 FLAGS_debug_level);
  IntFeatureSpace fs;
  fs.Init(kBoostXYBuckets, kBoostXYBuckets, kBoostDirBuckets);
  trainer->LoadUnicharset(FLAGS_U.c_str());
  // Get basic font information from font_properties.
  if (!FLAGS_F.empty()) {
    if (!trainer->LoadFontInfo(FLAGS_F.c_str())) {
      return {};
    }
  }
  if (!FLAGS_X.empty()) {
    if (!trainer->LoadXHeights(FLAGS_X.c_str())) {
      return {};
    }
  }
  trainer->SetFeatureSpace(fs);
  // Load training data from .tr files in filelist (terminated by nullptr).
  for (const char *page_name = *filelist++; page_name != nullptr; page_name = *filelist++) {
    tprintf("Reading %s ...\n", page_name);
    trainer->ReadTrainingSamples(page_name, feature_defs, false);

    // If there is a file with [lang].[fontname].exp[num].fontinfo present,
    // read font spacing information in to fontinfo_table.
    int pagename_len = strlen(page_name);
    char *fontinfo_file_name = new char[pagename_len + 7];
    strncpy(fontinfo_file_name, page_name, pagename_len - 2);  // remove "tr"
    strcpy(fontinfo_file_name + pagename_len - 2, "fontinfo"); // +"fontinfo"
    trainer->AddSpacingInfo(fontinfo_file_name);
    delete[] fontinfo_file_name;

    // Load the images into memory if required by the classifier.
    if (FLAGS_load_images) {
      std::string image_name = page_name;
      // Chop off the tr and replace with tif. Extension must be tif!
      image_name.resize(image_name.length() - 2);
      image_name += "tif";
      trainer->LoadPageImages(image_name.c_str());
    }
  }
  trainer->PostLoadCleanup();
  // Write the master trainer if required.
  if (!FLAGS_output_trainer.empty()) {
    FILE *fp = fopen(FLAGS_output_trainer.c_str(), "wb");
    if (fp == nullptr) {
      tprintf("Can't create saved trainer data!\n");
    } else {
      trainer->Serialize(fp);
      fclose(fp);
    }
  }
  trainer->PreTrainingSetup();
  if (!FLAGS_O.empty() && !trainer->unicharset().save_to_file(FLAGS_O.c_str())) {
    fprintf(stderr, "Failed to save unicharset to file %s\n", FLAGS_O.c_str());
    return {};
  }

  if (shape_table != nullptr) {
    // If we previously failed to load a shapetable, then shape clustering
    // wasn't run so make a flat one now.
    if (*shape_table == nullptr) {
      *shape_table = new ShapeTable;
      trainer->SetupFlatShapeTable(*shape_table);
      tprintf("Flat shape table summary: %s\n", (*shape_table)->SummaryStr().c_str());
    }
    (*shape_table)->set_unicharset(trainer->unicharset());
  }
  return trainer;
}