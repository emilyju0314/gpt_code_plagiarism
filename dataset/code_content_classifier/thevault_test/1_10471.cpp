void UnicharAmbigs::InitUnicharAmbigs(const UNICHARSET &unicharset, bool use_ambigs_for_adaption) {
  for (unsigned i = 0; i < unicharset.size(); ++i) {
    replace_ambigs_.push_back(nullptr);
    dang_ambigs_.push_back(nullptr);
    one_to_one_definite_ambigs_.push_back(nullptr);
    if (use_ambigs_for_adaption) {
      ambigs_for_adaption_.push_back(nullptr);
      reverse_ambigs_for_adaption_.push_back(nullptr);
    }
  }
}