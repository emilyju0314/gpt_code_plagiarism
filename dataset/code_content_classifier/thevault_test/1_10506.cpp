FILE *Tesseract::init_recog_training(const char *filename) {
  if (tessedit_ambigs_training) {
    tessedit_tess_adaption_mode.set_value(0); // turn off adaption
    tessedit_enable_doc_dict.set_value(false); // turn off document dictionary
    // Explore all segmentations.
    getDict().stopper_no_acceptable_choices.set_value(true);
  }

  std::string output_fname = filename;
  const char *lastdot = strrchr(output_fname.c_str(), '.');
  if (lastdot != nullptr) {
    output_fname[lastdot - output_fname.c_str()] = '\0';
  }
  output_fname += ".txt";
  FILE *output_file = fopen(output_fname.c_str(), "a+");
  if (output_file == nullptr) {
    tprintf("Error: Could not open file %s\n", output_fname.c_str());
    ASSERT_HOST(output_file);
  }
  return output_file;
}