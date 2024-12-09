static int16_t ordinalForDylibSymbol(const DylibSymbol &dysym) {
  if (config->namespaceKind == NamespaceKind::flat || dysym.isDynamicLookup())
    return static_cast<int16_t>(BIND_SPECIAL_DYLIB_FLAT_LOOKUP);
  assert(dysym.getFile()->isReferenced());
  return dysym.getFile()->ordinal;
}