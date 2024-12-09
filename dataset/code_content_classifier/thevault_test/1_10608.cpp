ADAPT_CLASS_STRUCT *ReadAdaptedClass(TFile *fp) {
  int NumTempProtos;
  int NumConfigs;
  int i;
  ADAPT_CLASS_STRUCT *Class;

  /* first read high level adapted class structure */
  Class = new ADAPT_CLASS_STRUCT;
  fp->FRead(Class, sizeof(ADAPT_CLASS_STRUCT), 1);

  /* then read in the definitions of the permanent protos and configs */
  Class->PermProtos = NewBitVector(MAX_NUM_PROTOS);
  Class->PermConfigs = NewBitVector(MAX_NUM_CONFIGS);
  fp->FRead(Class->PermProtos, sizeof(uint32_t), WordsInVectorOfSize(MAX_NUM_PROTOS));
  fp->FRead(Class->PermConfigs, sizeof(uint32_t), WordsInVectorOfSize(MAX_NUM_CONFIGS));

  /* then read in the list of temporary protos */
  fp->FRead(&NumTempProtos, sizeof(int), 1);
  Class->TempProtos = NIL_LIST;
  for (i = 0; i < NumTempProtos; i++) {
    auto TempProto = new TEMP_PROTO_STRUCT;
    fp->FRead(TempProto, sizeof(TEMP_PROTO_STRUCT), 1);
    Class->TempProtos = push_last(Class->TempProtos, TempProto);
  }

  /* then read in the adapted configs */
  fp->FRead(&NumConfigs, sizeof(int), 1);
  for (i = 0; i < NumConfigs; i++) {
    if (test_bit(Class->PermConfigs, i)) {
      Class->Config[i].Perm = ReadPermConfig(fp);
    } else {
      Class->Config[i].Temp = ReadTempConfig(fp);
    }
  }

  return (Class);

}