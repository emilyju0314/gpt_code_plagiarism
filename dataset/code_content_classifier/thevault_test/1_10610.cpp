PERM_CONFIG_STRUCT *ReadPermConfig(TFile *fp) {
  auto Config = new PERM_CONFIG_STRUCT;
  uint8_t NumAmbigs;
  fp->FRead(&NumAmbigs, sizeof(NumAmbigs), 1);
  Config->Ambigs = new UNICHAR_ID[NumAmbigs + 1];
  fp->FRead(Config->Ambigs, sizeof(UNICHAR_ID), NumAmbigs);
  Config->Ambigs[NumAmbigs] = -1;
  fp->FRead(&(Config->FontinfoId), sizeof(int), 1);

  return (Config);

}