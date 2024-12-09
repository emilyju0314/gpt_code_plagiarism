static Optional<unsigned>
tryParseObjCMethodName(StringRef Name, SmallVectorImpl<StringRef> &SlotNames,
                       const LangOptions &LangOpts) {
  // Accept replacements starting with - or + as valid ObjC method names.
  if (!Name.empty() && (Name.front() == '-' || Name.front() == '+'))
    Name = Name.drop_front(1);
  if (Name.empty())
    return None;
  Name.split(SlotNames, ':');
  unsigned NumParams;
  if (Name.back() == ':') {
    // Remove an empty string at the end that doesn't represent any slot.
    SlotNames.pop_back();
    NumParams = SlotNames.size();
  } else {
    if (SlotNames.size() != 1)
      // Not a valid method name, just a colon-separated string.
      return None;
    NumParams = 0;
  }
  // Verify all slot names are valid.
  bool AllowDollar = LangOpts.DollarIdents;
  for (StringRef S : SlotNames) {
    if (S.empty())
      continue;
    if (!isValidIdentifier(S, AllowDollar))
      return None;
  }
  return NumParams;
}