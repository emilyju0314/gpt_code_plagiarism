const char *LTRResultIterator::WordLattice(int *lattice_size) const {
  if (it_->word() == nullptr) {
    return nullptr; // Already at the end!
  }
  if (it_->word()->blamer_bundle == nullptr) {
    return nullptr;
  }
  *lattice_size = it_->word()->blamer_bundle->lattice_size();
  return it_->word()->blamer_bundle->lattice_data();
}