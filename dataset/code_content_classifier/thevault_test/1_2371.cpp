void Parse_Table::add(Parse_Table const &source) noexcept(false) {
  // Preallocate storage.
  vec.reserve(vec.size() + source.vec.size());

  // Add the new keywords.
  for (auto const &src : source.vec)
    vec.push_back(src);

  sort_table_();

  Ensure(check_class_invariants());
}