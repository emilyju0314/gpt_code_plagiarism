ErrOr<FoundMember> FindMemberWithErr(const Collection* base, const ParsedIdentifier& identifier) {
  if (!base) {
    return Err("Can't resolve '%s' on non-struct/class/union value.",
               identifier.GetFullName().c_str());
  }

  FindNameOptions options(FindNameOptions::kNoKinds);
  options.find_vars = true;

  std::vector<FoundName> found;
  FindMember(FindNameContext(), options, base, identifier, nullptr, &found);
  if (!found.empty()) {
    FXL_DCHECK(found[0].kind() == FoundName::kMemberVariable);
    return found[0].member();
  }

  return Err("No member '%s' in %s '%s'.", identifier.GetFullName().c_str(), base->GetKindString(),
             base->GetFullName().c_str());
}