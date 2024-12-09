WERD_RES *RecodeBeamSearch::InitializeWord(bool leading_space,
                                           const TBOX &line_box, int word_start,
                                           int word_end, float space_certainty,
                                           const UNICHARSET *unicharset,
                                           const std::vector<int> &xcoords,
                                           float scale_factor) {
  // Make a fake blob for each non-zero label.
  C_BLOB_LIST blobs;
  C_BLOB_IT b_it(&blobs);
  for (int i = word_start; i < word_end; ++i) {
    if (static_cast<unsigned>(i + 1) < character_boundaries_.size()) {
      TBOX box(static_cast<int16_t>(
                   std::floor(character_boundaries_[i] * scale_factor)) +
                   line_box.left(),
               line_box.bottom(),
               static_cast<int16_t>(
                   std::ceil(character_boundaries_[i + 1] * scale_factor)) +
                   line_box.left(),
               line_box.top());
      b_it.add_after_then_move(C_BLOB::FakeBlob(box));
    }
  }
  // Make a fake word from the blobs.
  WERD *word = new WERD(&blobs, leading_space, nullptr);
  // Make a WERD_RES from the word.
  auto *word_res = new WERD_RES(word);
  word_res->end = word_end - word_start + leading_space;
  word_res->uch_set = unicharset;
  word_res->combination = true; // Give it ownership of the word.
  word_res->space_certainty = space_certainty;
  word_res->ratings = new MATRIX(word_end - word_start, 1);
  return word_res;
}