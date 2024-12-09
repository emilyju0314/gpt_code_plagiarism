bool TessdataManager::GetComponent(TessdataType type, TFile *fp) const {
  ASSERT_HOST(is_loaded_);
  if (entries_[type].empty()) {
    return false;
  }
  fp->Open(&entries_[type][0], entries_[type].size());
  fp->set_swap(swap_);
  return true;
}