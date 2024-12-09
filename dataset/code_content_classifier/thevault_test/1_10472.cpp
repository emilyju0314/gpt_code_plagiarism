void UnicharAmbigs::LoadUniversal(const UNICHARSET &encoder_set, UNICHARSET *unicharset) {
  TFile file;
  if (!file.Open(kUniversalAmbigsFile, ksizeofUniversalAmbigsFile)) {
    return;
  }
  LoadUnicharAmbigs(encoder_set, &file, 0, false, unicharset);
}