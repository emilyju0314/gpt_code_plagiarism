static bool isValidOSObjectOutParameter(const Decl *D) {
  const auto *PVD = dyn_cast<ParmVarDecl>(D);
  if (!PVD)
    return false;
  QualType QT = PVD->getType();
  QualType PT = QT->getPointeeType();
  return !PT.isNull() && isValidSubjectOfOSAttribute(PT);
}