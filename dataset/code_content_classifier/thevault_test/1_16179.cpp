static bool needsMerge(MergeLattice lattice) {
  if (lattice.getSize() > 1) {
    return true;
  }

  int notRandomAccess = 0;
  for (auto& iterator : lattice.getIterators()) {
    if ((!iterator.isRandomAccess()) && (++notRandomAccess > 1)) {
      return true;
    }
  }
  return false;
}