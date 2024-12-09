void Wordrec::program_editdown(int32_t elasped_time) {
#ifndef DISABLED_LEGACY_ENGINE
  EndAdaptiveClassifier();
#endif // ndef DISABLED_LEGACY_ENGINE
  getDict().End();
}