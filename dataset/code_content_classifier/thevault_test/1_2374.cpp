void Parse_Table::set_flags(unsigned char const f) {
  flags_ = f;

  add(nullptr, 0U);
  // The keyword list needs to be sorted and checked.  For example, if the
  // options are changed so that a previously case-sensitive Parse_Table is no
  // longer case-sensitive, then the ordering changes, and previously
  // unambiguous keywords may become ambiguous.

  Ensure(check_class_invariants());
  Ensure(get_flags() == f);
}