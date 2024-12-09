static bool isValidSwiftContextType(QualType Ty) {
  if (!Ty->hasPointerRepresentation())
    return Ty->isDependentType();
  return Ty->getPointeeType().getAddressSpace() == LangAS::Default;
}