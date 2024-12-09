static void printGenericSpecializationInfo(
    raw_ostream &OS, StringRef Kind, StringRef Name,
    const GenericSpecializationInformation *SpecializationInfo,
    SubstitutionList Subs = SubstitutionList()) {
  if (!SpecializationInfo)
    return;

  auto PrintSubstitutions = [&](SubstitutionList Subs) {
    OS << '<';
    interleave(Subs,
               [&](const Substitution &s) { OS << s.getReplacement(); },
               [&] { OS << ", "; });
    OS << '>';
  };

  OS << "// Generic specialization information for " << Kind << " " << Name;
  if (!Subs.empty()) {
    OS << " ";
    PrintSubstitutions(Subs);
  }

  OS << ":\n";

  while (SpecializationInfo) {
    OS << "// Caller: " << SpecializationInfo->getCaller()->getName() << '\n';
    OS << "// Parent: " << SpecializationInfo->getParent()->getName() << '\n';
    OS << "// Substitutions: ";
    PrintSubstitutions(SpecializationInfo->getSubstitutions());
    OS << '\n';
    OS << "//\n";
    if (!SpecializationInfo->getCaller()->isSpecialization())
      return;
    SpecializationInfo =
      SpecializationInfo->getCaller()->getSpecializationInfo();
  }
}