const char *LTRResultIterator::WordRecognitionLanguage() const {
  if (it_->word() == nullptr || it_->word()->tesseract == nullptr) {
    return nullptr;
  }
  return it_->word()->tesseract->lang.c_str();
}