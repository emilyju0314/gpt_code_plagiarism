void WERD_RES::InsertSeam(int blob_number, SEAM *seam) {
  // Insert the seam into the SEAMS array.
  seam->PrepareToInsertSeam(seam_array, chopped_word->blobs, blob_number, true);
  seam_array.insert(seam_array.begin() + blob_number, seam);
  if (ratings != nullptr) {
    // Expand the ratings matrix.
    ratings = ratings->ConsumeAndMakeBigger(blob_number);
    // Fix all the segmentation states.
    if (raw_choice != nullptr) {
      raw_choice->UpdateStateForSplit(blob_number);
    }
    WERD_CHOICE_IT wc_it(&best_choices);
    for (wc_it.mark_cycle_pt(); !wc_it.cycled_list(); wc_it.forward()) {
      WERD_CHOICE *choice = wc_it.data();
      choice->UpdateStateForSplit(blob_number);
    }
    SetupBlobWidthsAndGaps();
  }
}