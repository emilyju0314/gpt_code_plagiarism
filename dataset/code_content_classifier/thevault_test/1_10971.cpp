BLOCK_RES::BLOCK_RES(bool merge_similar_words, BLOCK *the_block) {
  ROW_IT row_it(the_block->row_list());
  ROW_RES_IT row_res_it(&row_res_list);

  char_count = 0;
  rej_count = 0;
  font_class = -1; // not assigned
  x_height = -1.0;
  font_assigned = false;
  row_count = 0;

  block = the_block;

  for (row_it.mark_cycle_pt(); !row_it.cycled_list(); row_it.forward()) {
    row_res_it.add_to_end(new ROW_RES(merge_similar_words, row_it.data()));
  }
}