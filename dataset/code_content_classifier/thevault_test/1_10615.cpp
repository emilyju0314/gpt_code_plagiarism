void WriteTempConfig(FILE *File, TEMP_CONFIG_STRUCT *Config) {
  assert(Config != nullptr);

  fwrite(Config, sizeof(TEMP_CONFIG_STRUCT), 1, File);
  fwrite(Config->Protos, sizeof(uint32_t), Config->ProtoVectorSize, File);

}