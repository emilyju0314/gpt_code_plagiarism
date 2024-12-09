void WERD_RES::ConsumeWordResults(WERD_RES *word) {
  denorm = word->denorm;
  blob_row = word->blob_row;
  MovePointerData(&chopped_word, &word->chopped_word);
  MovePointerData(&rebuild_word, &word->rebuild_word);
  MovePointerData(&box_word, &word->box_word);
  for (auto data : seam_array) {
    delete data;
  }
  seam_array = word->seam_array;
  word->seam_array.clear();
  // TODO: optimize moves.
  best_state = word->best_state;
  word->best_state.clear();
  correct_text = word->correct_text;
  word->correct_text.clear();
  blob_widths = word->blob_widths;
  word->blob_widths.clear();
  blob_gaps = word->blob_gaps;
  word->blob_gaps.clear();
  if (ratings != nullptr) {
    ratings->delete_matrix_pointers();
  }
  MovePointerData(&ratings, &word->ratings);
  best_choice = word->best_choice;
  MovePointerData(&raw_choice, &word->raw_choice);
  best_choices.clear();
  WERD_CHOICE_IT wc_it(&best_choices);
  wc_it.add_list_after(&word->best_choices);
  reject_map = word->reject_map;
  if (word->blamer_bundle != nullptr) {
    assert(blamer_bundle != nullptr);
    blamer_bundle->CopyResults(*(word->blamer_bundle));
  }
  CopySimpleFields(*word);
}