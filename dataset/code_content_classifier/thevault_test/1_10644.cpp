void Wordrec::program_editup(const std::string &textbase, TessdataManager *init_classifier,
                             TessdataManager *init_dict) {
  if (!textbase.empty()) {
    imagefile = textbase;
  }
#ifndef DISABLED_LEGACY_ENGINE
  InitFeatureDefs(&feature_defs_);
  InitAdaptiveClassifier(init_classifier);
  if (init_dict) {
    getDict().SetupForLoad(Dict::GlobalDawgCache());
    getDict().Load(lang, init_dict);
    getDict().FinishLoad();
  }
  pass2_ok_split = chop_ok_split;
#endif // ndef DISABLED_LEGACY_ENGINE
}