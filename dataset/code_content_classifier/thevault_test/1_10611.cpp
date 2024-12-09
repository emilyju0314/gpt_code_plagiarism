TEMP_CONFIG_STRUCT *ReadTempConfig(TFile *fp) {
  auto Config = new TEMP_CONFIG_STRUCT;
  fp->FRead(Config, sizeof(TEMP_CONFIG_STRUCT), 1);

  Config->Protos = NewBitVector(Config->ProtoVectorSize * BITSINLONG);
  fp->FRead(Config->Protos, sizeof(uint32_t), Config->ProtoVectorSize);

  return (Config);

}