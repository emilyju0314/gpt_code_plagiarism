int AddConfigToClass(CLASS_TYPE Class) {
  int NewNumConfigs;
  int NewConfig;
  int MaxNumProtos;
  BIT_VECTOR Config;

  MaxNumProtos = Class->MaxNumProtos;
  ASSERT_HOST(MaxNumProtos <= MAX_NUM_PROTOS);

  if (Class->NumConfigs >= Class->MaxNumConfigs) {
    /* add configs in CONFIG_INCREMENT chunks at a time */
    NewNumConfigs =
        (((Class->MaxNumConfigs + CONFIG_INCREMENT) / CONFIG_INCREMENT) * CONFIG_INCREMENT);

    Class->Configurations.resize(NewNumConfigs);
    Class->MaxNumConfigs = NewNumConfigs;
  }
  NewConfig = Class->NumConfigs++;
  Config = NewBitVector(MAX_NUM_PROTOS);
  Class->Configurations[NewConfig] = Config;
  zero_all_bits(Config, WordsInVectorOfSize(MAX_NUM_PROTOS));

  return (NewConfig);
}