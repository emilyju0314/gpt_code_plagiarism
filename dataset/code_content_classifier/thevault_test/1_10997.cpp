bool WERD_RES::ConditionalBlobMerge(
    const std::function<UNICHAR_ID(UNICHAR_ID, UNICHAR_ID)> &class_cb,
    const std::function<bool(const TBOX &, const TBOX &)> &box_cb) {
  ASSERT_HOST(best_choice->empty() || ratings != nullptr);
  bool modified = false;
  for (unsigned i = 0; i + 1 < best_choice->length(); ++i) {
    UNICHAR_ID new_id =
        class_cb(best_choice->unichar_id(i), best_choice->unichar_id(i + 1));
    if (new_id != INVALID_UNICHAR_ID &&
        (box_cb == nullptr ||
         box_cb(box_word->BlobBox(i), box_word->BlobBox(i + 1)))) {
      // Raw choice should not be fixed.
      best_choice->set_unichar_id(new_id, i);
      modified = true;
      MergeAdjacentBlobs(i);
      const MATRIX_COORD &coord = best_choice->MatrixCoord(i);
      if (!coord.Valid(*ratings)) {
        ratings->IncreaseBandSize(coord.row + 1 - coord.col);
      }
      BLOB_CHOICE_LIST *blob_choices = GetBlobChoices(i);
      if (FindMatchingChoice(new_id, blob_choices) == nullptr) {
        // Insert a fake result.
        auto *blob_choice = new BLOB_CHOICE;
        blob_choice->set_unichar_id(new_id);
        BLOB_CHOICE_IT bc_it(blob_choices);
        bc_it.add_before_then_move(blob_choice);
      }
    }
  }
  return modified;
}