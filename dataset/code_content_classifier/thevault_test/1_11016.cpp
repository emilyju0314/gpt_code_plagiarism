WERD_RES *PAGE_RES_IT::internal_forward(bool new_block, bool empty_ok) {
  bool new_row = false;

  prev_block_res = block_res;
  prev_row_res = row_res;
  prev_word_res = word_res;
  block_res = next_block_res;
  row_res = next_row_res;
  word_res = next_word_res;
  wr_it_of_current_word = wr_it_of_next_word;
  next_block_res = nullptr;
  next_row_res = nullptr;
  next_word_res = nullptr;

  while (!block_res_it.cycled_list()) {
    if (new_block) {
      new_block = false;
      row_res_it.set_to_list(&block_res_it.data()->row_res_list);
      row_res_it.mark_cycle_pt();
      if (row_res_it.empty() && empty_ok) {
        next_block_res = block_res_it.data();
        break;
      }
      new_row = true;
    }
    while (!row_res_it.cycled_list()) {
      if (new_row) {
        new_row = false;
        word_res_it.set_to_list(&row_res_it.data()->word_res_list);
        word_res_it.mark_cycle_pt();
      }
      // Skip any part_of_combo words.
      while (!word_res_it.cycled_list() && word_res_it.data()->part_of_combo) {
        word_res_it.forward();
      }
      if (!word_res_it.cycled_list()) {
        next_block_res = block_res_it.data();
        next_row_res = row_res_it.data();
        next_word_res = word_res_it.data();
        wr_it_of_next_word = word_res_it;
        word_res_it.forward();
        goto foundword;
      }
      // end of row reached
      row_res_it.forward();
      new_row = true;
    }
    // end of block reached
    block_res_it.forward();
    new_block = true;
  }
foundword:
  // Update prev_word_best_choice pointer.
  if (page_res != nullptr && page_res->prev_word_best_choice != nullptr) {
    *page_res->prev_word_best_choice = (new_block || prev_word_res == nullptr)
                                           ? nullptr
                                           : prev_word_res->best_choice;
  }
  return word_res;
}