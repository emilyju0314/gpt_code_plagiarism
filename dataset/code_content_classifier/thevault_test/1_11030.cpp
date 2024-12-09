char *LTRResultIterator::WordNormedUTF8Text() const {
  if (it_->word() == nullptr) {
    return nullptr; // Already at the end!
  }
  std::string ocr_text;
  WERD_CHOICE *best_choice = it_->word()->best_choice;
  const UNICHARSET *unicharset = it_->word()->uch_set;
  ASSERT_HOST(best_choice != nullptr);
  for (unsigned i = 0; i < best_choice->length(); ++i) {
    ocr_text += unicharset->get_normed_unichar(best_choice->unichar_id(i));
  }
  auto length = ocr_text.length() + 1;
  char *result = new char[length];
  strncpy(result, ocr_text.c_str(), length);
  return result;
}