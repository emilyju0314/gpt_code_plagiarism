void PAGE_RES_IT::ReplaceCurrentWord(
    tesseract::PointerVector<WERD_RES> *words) {
  if (words->empty()) {
    DeleteCurrentWord();
    return;
  }
  WERD_RES *input_word = word();
  // Set the BOL/EOL flags on the words from the input word.
  if (input_word->word->flag(W_BOL)) {
    (*words)[0]->word->set_flag(W_BOL, true);
  } else {
    (*words)[0]->word->set_blanks(input_word->word->space());
  }
  words->back()->word->set_flag(W_EOL, input_word->word->flag(W_EOL));

  // Move the blobs from the input word to the new set of words.
  // If the input word_res is a combination, then the replacements will also be
  // combinations, and will own their own words. If the input word_res is not a
  // combination, then the final replacements will not be either, (although it
  // is allowed for the input words to be combinations) and their words
  // will get put on the row list. This maintains the ownership rules.
  WERD_IT w_it(row()->row->word_list());
  if (!input_word->combination) {
    for (w_it.mark_cycle_pt(); !w_it.cycled_list(); w_it.forward()) {
      WERD *word = w_it.data();
      if (word == input_word->word) {
        break;
      }
    }
    // w_it is now set to the input_word's word.
    ASSERT_HOST(!w_it.cycled_list());
  }
  // Insert into the appropriate place in the ROW_RES.
  WERD_RES_IT wr_it(&row()->word_res_list);
  for (wr_it.mark_cycle_pt(); !wr_it.cycled_list(); wr_it.forward()) {
    WERD_RES *word = wr_it.data();
    if (word == input_word) {
      break;
    }
  }
  ASSERT_HOST(!wr_it.cycled_list());
  // Since we only have an estimate of the bounds between blobs, use the blob
  // x-middle as the determiner of where to put the blobs
  C_BLOB_IT src_b_it(input_word->word->cblob_list());
  src_b_it.sort(&C_BLOB::SortByXMiddle);
  C_BLOB_IT rej_b_it(input_word->word->rej_cblob_list());
  rej_b_it.sort(&C_BLOB::SortByXMiddle);
  TBOX clip_box;
  for (size_t w = 0; w < words->size(); ++w) {
    WERD_RES *word_w = (*words)[w];
    clip_box = ComputeWordBounds(*words, w, clip_box, wr_it_of_current_word);
    // Compute blob boundaries.
    std::vector<int> blob_ends;
    C_BLOB_LIST *next_word_blobs =
        w + 1 < words->size() ? (*words)[w + 1]->word->cblob_list() : nullptr;
    ComputeBlobEnds(*word_w, clip_box, next_word_blobs, &blob_ends);
    // Remove the fake blobs on the current word, but keep safe for back-up if
    // no blob can be found.
    C_BLOB_LIST fake_blobs;
    C_BLOB_IT fake_b_it(&fake_blobs);
    fake_b_it.add_list_after(word_w->word->cblob_list());
    fake_b_it.move_to_first();
    word_w->word->cblob_list()->clear();
    C_BLOB_IT dest_it(word_w->word->cblob_list());
    // Build the box word as we move the blobs.
    auto *box_word = new tesseract::BoxWord;
    for (size_t i = 0; i < blob_ends.size(); ++i, fake_b_it.forward()) {
      int end_x = blob_ends[i];
      TBOX blob_box;
      // Add the blobs up to end_x.
      while (!src_b_it.empty() &&
             src_b_it.data()->bounding_box().x_middle() < end_x) {
        blob_box += MoveAndClipBlob(&src_b_it, &dest_it, clip_box);
        src_b_it.forward();
      }
      while (!rej_b_it.empty() &&
             rej_b_it.data()->bounding_box().x_middle() < end_x) {
        blob_box += MoveAndClipBlob(&rej_b_it, &dest_it, clip_box);
        rej_b_it.forward();
      }
      if (blob_box.null_box()) {
        // Use the original box as a back-up.
        blob_box = MoveAndClipBlob(&fake_b_it, &dest_it, clip_box);
      }
      box_word->InsertBox(i, blob_box);
    }
    delete word_w->box_word;
    word_w->box_word = box_word;
    if (!input_word->combination) {
      // Insert word_w->word into the ROW. It doesn't own its word, so the
      // ROW needs to own it.
      w_it.add_before_stay_put(word_w->word);
      word_w->combination = false;
    }
    (*words)[w] = nullptr; // We are taking ownership.
    wr_it.add_before_stay_put(word_w);
  }
  // We have taken ownership of the words.
  words->clear();
  // Delete the current word, which has been replaced. We could just call
  // DeleteCurrentWord, but that would iterate both lists again, and we know
  // we are already in the right place.
  if (!input_word->combination) {
    delete w_it.extract();
  }
  delete wr_it.extract();
  ResetWordIterator();
}