void PAGE_RES_IT::ResetWordIterator() {
  if (row_res == next_row_res) {
    // Reset the member iterator so it can move forward and detect the
    // cycled_list state correctly.
    word_res_it.move_to_first();
    for (word_res_it.mark_cycle_pt();
         !word_res_it.cycled_list() && word_res_it.data() != next_word_res;
         word_res_it.forward()) {
      if (!word_res_it.data()->part_of_combo) {
        if (prev_row_res == row_res) {
          prev_word_res = word_res;
        }
        word_res = word_res_it.data();
      }
    }
    ASSERT_HOST(!word_res_it.cycled_list());
    wr_it_of_next_word = word_res_it;
    word_res_it.forward();
  } else {
    // word_res_it is OK, but reset word_res and prev_word_res if needed.
    WERD_RES_IT wr_it(&row_res->word_res_list);
    for (wr_it.mark_cycle_pt(); !wr_it.cycled_list(); wr_it.forward()) {
      if (!wr_it.data()->part_of_combo) {
        if (prev_row_res == row_res) {
          prev_word_res = word_res;
        }
        word_res = wr_it.data();
      }
    }
  }
}