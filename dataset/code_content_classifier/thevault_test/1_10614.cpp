void WritePermConfig(FILE *File, PERM_CONFIG_STRUCT *Config) {
  uint8_t NumAmbigs = 0;

  assert(Config != nullptr);
  while (Config->Ambigs[NumAmbigs] > 0) {
    ++NumAmbigs;
  }

  fwrite(&NumAmbigs, sizeof(uint8_t), 1, File);
  fwrite(Config->Ambigs, sizeof(UNICHAR_ID), NumAmbigs, File);
  fwrite(&(Config->FontinfoId), sizeof(int), 1, File);
}