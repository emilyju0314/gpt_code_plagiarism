void FreeClassFields(CLASS_TYPE Class) {
  if (Class) {
    for (int i = 0; i < Class->NumConfigs; i++) {
      FreeBitVector(Class->Configurations[i]);
    }
  }
}