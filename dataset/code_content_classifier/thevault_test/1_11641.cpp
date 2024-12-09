AssertionResult Equal(const std::vector<ContextConstraint>& a,
                      const std::vector<ContextConstraint>& b) {
  if (a.size() != b.size()) {
    return AssertionFailure()
           << "a.size (" << a.size() << ") != b.size (" << b.size() << ")";
  }
  for (int i = 0; i < static_cast<int>(a.size()); ++i) {
    if (a[i].presence != b[i].presence || a[i].type_key != b[i].type_key ||
        a[i].name != b[i].name) {
      return AssertionFailure()
             << "a[" << i << "] (" << a[i].ToString() << ") != b[" << i << "] ("
             << b[i].ToString() << ")";
    }
  }
  return AssertionSuccess();
}