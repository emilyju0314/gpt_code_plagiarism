WERD_RES *PAGE_RES_IT::InsertSimpleCloneWord(const WERD_RES &clone_res,
                                             WERD *new_word) {
  // Make a WERD_RES for the new_word.
  auto *new_res = new WERD_RES(new_word);
  new_res->CopySimpleFields(clone_res);
  new_res->combination = true;
  // Insert into the appropriate place in the ROW_RES.
  WERD_RES_IT wr_it(&row()->word_res_list);
  for (wr_it.mark_cycle_pt(); !wr_it.cycled_list(); wr_it.forward()) {
    WERD_RES *word = wr_it.data();
    if (word == word_res) {
      break;
    }
  }
  ASSERT_HOST(!wr_it.cycled_list());
  wr_it.add_before_then_move(new_res);
  if (wr_it.at_first()) {
    // This is the new first word, so reset the member iterator so it
    // detects the cycled_list state correctly.
    ResetWordIterator();
  }
  return new_res;
}