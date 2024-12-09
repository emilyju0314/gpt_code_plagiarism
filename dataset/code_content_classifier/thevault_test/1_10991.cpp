void WERD_RES::CloneChoppedToRebuild() {
  delete rebuild_word;
  rebuild_word = new TWERD(*chopped_word);
  SetupBoxWord();
  auto word_len = box_word->length();
  best_state.reserve(word_len);
  correct_text.reserve(word_len);
  for (unsigned i = 0; i < word_len; ++i) {
    best_state.push_back(1);
    correct_text.emplace_back("");
  }
}