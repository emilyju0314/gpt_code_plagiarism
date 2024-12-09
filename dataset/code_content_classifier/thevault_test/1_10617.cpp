int Tesseract::init_tesseract(const std::string &arg0, const std::string &textbase,
                              const std::string &language, OcrEngineMode oem, char **configs,
                              int configs_size, const std::vector<std::string> *vars_vec,
                              const std::vector<std::string> *vars_values,
                              bool set_only_non_debug_params, TessdataManager *mgr) {
  std::vector<std::string> langs_to_load;
  std::vector<std::string> langs_not_to_load;
  ParseLanguageString(language, &langs_to_load, &langs_not_to_load);

  for (auto *lang : sub_langs_) {
    delete lang;
  }

  // Set the basename, compute the data directory.
  main_setup(arg0, textbase);

  sub_langs_.clear();
  // Find the first loadable lang and load into this.
  // Add any languages that this language requires
  bool loaded_primary = false;
  // Load the rest into sub_langs_.
  // A range based for loop does not work here because langs_to_load
  // might be changed in the loop when a new submodel is found.
  for (auto &lang_to_load : langs_to_load) {
    if (!IsStrInList(lang_to_load, langs_not_to_load)) {
      const char *lang_str = lang_to_load.c_str();
      Tesseract *tess_to_init;
      if (!loaded_primary) {
        tess_to_init = this;
      } else {
        tess_to_init = new Tesseract;
        tess_to_init->main_setup(arg0, textbase);
      }

      int result = tess_to_init->init_tesseract_internal(arg0, textbase, lang_str, oem, configs,
                                                         configs_size, vars_vec, vars_values,
                                                         set_only_non_debug_params, mgr);
      // Forget that language, but keep any reader we were given.
      mgr->Clear();

      if (!loaded_primary) {
        if (result < 0) {
          tprintf("Failed loading language '%s'\n", lang_str);
        } else {
          ParseLanguageString(tess_to_init->tessedit_load_sublangs, &langs_to_load,
                              &langs_not_to_load);
          loaded_primary = true;
        }
      } else {
        if (result < 0) {
          tprintf("Failed loading language '%s'\n", lang_str);
          delete tess_to_init;
        } else {
          sub_langs_.push_back(tess_to_init);
          // Add any languages that this language requires
          ParseLanguageString(tess_to_init->tessedit_load_sublangs, &langs_to_load,
                              &langs_not_to_load);
        }
      }
    }
  }
  if (!loaded_primary && !langs_to_load.empty()) {
    tprintf("Tesseract couldn't load any languages!\n");
    return -1; // Couldn't load any language!
  }
#ifndef DISABLED_LEGACY_ENGINE
  if (!sub_langs_.empty()) {
    // In multilingual mode word ratings have to be directly comparable,
    // so use the same language model weights for all languages:
    // use the primary language's params model if
    // tessedit_use_primary_params_model is set,
    // otherwise use default language model weights.
    if (tessedit_use_primary_params_model) {
      for (auto &sub_lang : sub_langs_) {
        sub_lang->language_model_->getParamsModel().Copy(this->language_model_->getParamsModel());
      }
      tprintf("Using params model of the primary language\n");
    } else {
      this->language_model_->getParamsModel().Clear();
      for (auto &sub_lang : sub_langs_) {
        sub_lang->language_model_->getParamsModel().Clear();
      }
    }
  }

  SetupUniversalFontIds();
#endif // ndef DISABLED_LEGACY_ENGINE
  return 0;
}