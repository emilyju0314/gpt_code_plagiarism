bool ReferencesMainFunction(const InputLocation& loc) {
  if (loc.type != InputLocation::Type::kName || loc.name.components().size() != 1)
    return false;
  return loc.name.components()[0].name() == "@main";
}