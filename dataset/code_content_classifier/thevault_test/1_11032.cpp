bool LTRResultIterator::SymbolIsSuperscript() const {
  if (cblob_it_ == nullptr && it_->word() != nullptr) {
    return it_->word()->best_choice->BlobPosition(blob_index_) == SP_SUPERSCRIPT;
  }
  return false;
}