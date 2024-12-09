void AddAdaptedClass(ADAPT_TEMPLATES_STRUCT *Templates, ADAPT_CLASS_STRUCT *Class, CLASS_ID ClassId) {
  assert(Templates != nullptr);
  assert(Class != nullptr);
  assert(LegalClassId(ClassId));
  assert(UnusedClassIdIn(Templates->Templates, ClassId));
  assert(Class->NumPermConfigs == 0);

  auto IntClass = new INT_CLASS_STRUCT(1, 1);
  AddIntClass(Templates->Templates, ClassId, IntClass);

  assert(Templates->Class[ClassId] == nullptr);
  Templates->Class[ClassId] = Class;

}