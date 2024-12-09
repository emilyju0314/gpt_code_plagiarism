static bool isValidSwiftErrorResultType(QualType Ty) {
  if (const auto *PtrType = Ty->getAs<PointerType>()) {
    Ty = PtrType->getPointeeType();
  } else if (const auto *RefType = Ty->getAs<ReferenceType>()) {
    Ty = RefType->getPointeeType();
  } else {
    return Ty->isDependentType();
  }
  if (!Ty.getQualifiers().empty())
    return false;
  return isValidSwiftContextType(Ty);
}