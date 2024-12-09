void PAGE_RES_IT::DeleteCurrentWord() {
  // Check that this word is as we expect. part_of_combos are NEVER iterated
  // by the normal iterator, so we should never be trying to delete them.
  ASSERT_HOST(!word_res->part_of_combo);
  if (!word_res->combination) {
    // Combinations own their own word, so we won't find the word on the
    // row's word_list, but it is legitimate to try to delete them.
    // Delete word from the ROW when not a combination.
    WERD_IT w_it(row()->row->word_list());
    for (w_it.mark_cycle_pt(); !w_it.cycled_list(); w_it.forward()) {
      if (w_it.data() == word_res->word) {
        break;
      }
    }
    ASSERT_HOST(!w_it.cycled_list());
    delete w_it.extract();
  }
  // Remove the WERD_RES for the new_word.
  // Remove the WORD_RES from the ROW_RES.
  WERD_RES_IT wr_it(&row()->word_res_list);
  for (wr_it.mark_cycle_pt(); !wr_it.cycled_list(); wr_it.forward()) {
    if (wr_it.data() == word_res) {
      word_res = nullptr;
      break;
    }
  }
  ASSERT_HOST(!wr_it.cycled_list());
  delete wr_it.extract();
  ResetWordIterator();
}