int Tesseract::init_tesseract_internal(const std::string &arg0, const std::string &textbase,
                                       const std::string &language, OcrEngineMode oem,
                                       char **configs, int configs_size,
                                       const std::vector<std::string> *vars_vec,
                                       const std::vector<std::string> *vars_values,
                                       bool set_only_non_debug_params, TessdataManager *mgr) {
  if (!init_tesseract_lang_data(arg0, language, oem, configs, configs_size, vars_vec,
                                vars_values, set_only_non_debug_params, mgr)) {
    return -1;
  }
  if (tessedit_init_config_only) {
    return 0;
  }
  // If only LSTM will be used, skip loading Tesseract classifier's
  // pre-trained templates and dictionary.
  bool init_tesseract = tessedit_ocr_engine_mode != OEM_LSTM_ONLY;
  program_editup(textbase, init_tesseract ? mgr : nullptr, init_tesseract ? mgr : nullptr);
  return 0; // Normal exit
}