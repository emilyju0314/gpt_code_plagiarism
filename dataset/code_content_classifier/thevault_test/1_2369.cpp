void Parse_Table::add(Keyword const *const table, size_t const count) noexcept(false) {
  Require(count == 0 || table != nullptr);
  // Additional precondition checked in loop below

  // Preallocate storage.
  vec.reserve(vec.size() + count);

  // Add the new keywords.

  for (unsigned i = 0; i < count; i++) {
    Require(Is_Well_Formed_Keyword(table[i]));

    vec.push_back(table[i]);
  }

  sort_table_();

  Ensure(check_class_invariants());
}