CLASS_TYPE NewClass(int NumProtos, int NumConfigs) {
  CLASS_TYPE Class;

  Class = new CLASS_STRUCT;

  Class->Prototypes.resize(NumProtos);
  Class->Configurations.resize(NumConfigs);
  Class->MaxNumProtos = NumProtos;
  Class->MaxNumConfigs = NumConfigs;
  Class->NumProtos = 0;
  Class->NumConfigs = 0;
  return (Class);
}