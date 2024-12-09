bool ArcTypesMatch(const FstClass &a, const FstClass &b,
                   const string &op_name) {
  if (a.ArcType() != b.ArcType()) {
    LOG(ERROR) << "FSTs with non-matching arc types passed to " << op_name
               << ":\n\t" << a.ArcType() << " and " << b.ArcType();
    return false;
  } else {
    return true;
  }
}