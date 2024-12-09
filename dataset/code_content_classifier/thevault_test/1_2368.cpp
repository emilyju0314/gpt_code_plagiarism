Parse_Table::Parse_Table(Keyword const *const table, size_t const count, unsigned const flags)
    : vec(), flags_(static_cast<unsigned char>(flags)) {
  Require(count == 0 || table != nullptr);
  Require(count == 0 || std::find_if(table, table + count, Is_Well_Formed_Keyword));

  add(table, count);

  Ensure(check_class_invariants());
  Ensure(get_flags() == flags);
}