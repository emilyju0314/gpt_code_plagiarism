bool Sema::checkTargetAttr(SourceLocation LiteralLoc, StringRef AttrStr) {
  enum FirstParam { Unsupported, Duplicate };
  enum SecondParam { None, Architecture };
  for (auto Str : {"tune=", "fpmath="})
    if (AttrStr.find(Str) != StringRef::npos)
      return Diag(LiteralLoc, diag::warn_unsupported_target_attribute)
             << Unsupported << None << Str;

  TargetAttr::ParsedTargetAttr ParsedAttrs = TargetAttr::parse(AttrStr);

  if (!ParsedAttrs.Architecture.empty() &&
      !Context.getTargetInfo().isValidCPUName(ParsedAttrs.Architecture))
    return Diag(LiteralLoc, diag::warn_unsupported_target_attribute)
           << Unsupported << Architecture << ParsedAttrs.Architecture;

  if (ParsedAttrs.DuplicateArchitecture)
    return Diag(LiteralLoc, diag::warn_unsupported_target_attribute)
           << Duplicate << None << "arch=";

  for (const auto &Feature : ParsedAttrs.Features) {
    auto CurFeature = StringRef(Feature).drop_front(); // remove + or -.
    if (!Context.getTargetInfo().isValidFeatureName(CurFeature))
      return Diag(LiteralLoc, diag::warn_unsupported_target_attribute)
             << Unsupported << None << CurFeature;
  }

  return false;
}