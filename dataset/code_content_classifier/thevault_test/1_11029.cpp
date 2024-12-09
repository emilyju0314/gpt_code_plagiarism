char *LTRResultIterator::WordTruthUTF8Text() const {
  if (!HasTruthString()) {
    return nullptr;
  }
  std::string truth_text = it_->word()->blamer_bundle->TruthString();
  int length = truth_text.length() + 1;
  char *result = new char[length];
  strncpy(result, truth_text.c_str(), length);
  return result;
}