void Parse_Table::remove(char const *moniker) {
  // This is an order N operation as presently coded. N is never very large.
  for (auto i = vec.begin(); i != vec.end(); ++i) {
    if (!strcmp(i->moniker, moniker)) {
      vec.erase(i);
      Ensure(check_class_invariants());
      return;
    }
  }

  throw invalid_argument("keyword not found in Parse_Table::remove");
}