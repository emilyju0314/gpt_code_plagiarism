void WERD_RES::MergeAdjacentBlobs(unsigned index) {
  if (reject_map.length() == best_choice->length()) {
    reject_map.remove_pos(index);
  }
  best_choice->remove_unichar_id(index + 1);
  rebuild_word->MergeBlobs(index, index + 2);
  box_word->MergeBoxes(index, index + 2);
  if (index + 1 < best_state.size()) {
    best_state[index] += best_state[index + 1];
    best_state.erase(best_state.begin() + index + 1);
  }
}