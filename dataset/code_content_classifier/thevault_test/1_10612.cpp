void WriteAdaptedClass(FILE *File, ADAPT_CLASS_STRUCT *Class, int NumConfigs) {
  /* first write high level adapted class structure */
  fwrite(Class, sizeof(ADAPT_CLASS_STRUCT), 1, File);

  /* then write out the definitions of the permanent protos and configs */
  fwrite(Class->PermProtos, sizeof(uint32_t), WordsInVectorOfSize(MAX_NUM_PROTOS), File);
  fwrite(Class->PermConfigs, sizeof(uint32_t), WordsInVectorOfSize(MAX_NUM_CONFIGS), File);

  /* then write out the list of temporary protos */
  uint32_t NumTempProtos = Class->TempProtos->size();
  fwrite(&NumTempProtos, sizeof(NumTempProtos), 1, File);
  auto TempProtos = Class->TempProtos;
  iterate(TempProtos) {
    void *proto = TempProtos->node;
    fwrite(proto, sizeof(TEMP_PROTO_STRUCT), 1, File);
  }

  /* then write out the adapted configs */
  fwrite(&NumConfigs, sizeof(int), 1, File);
  for (int i = 0; i < NumConfigs; i++) {
    if (test_bit(Class->PermConfigs, i)) {
      WritePermConfig(File, Class->Config[i].Perm);
    } else {
      WriteTempConfig(File, Class->Config[i].Temp);
    }
  }

}