std::optional<std::string> GetPLTInputLocation(const InputLocation& loc) {
  if (loc.type != InputLocation::Type::kName || loc.name.components().size() != 1)
    return std::nullopt;

  const IdentifierComponent& comp = loc.name.components()[0];
  if (!StringEndsWith(comp.name(), "@plt"))
    return std::nullopt;

  return comp.name().substr(0, comp.name().size() - 4);
}