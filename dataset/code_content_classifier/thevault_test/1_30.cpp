std::pair<llvm::Value *, bool> CreateTerm::operator()(KOREPattern *pattern) {
  populateStaticSet(pattern);

  return createAllocation(pattern);
}