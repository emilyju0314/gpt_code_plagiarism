PAGE_RES::PAGE_RES(bool merge_similar_words, BLOCK_LIST *the_block_list,
                   WERD_CHOICE **prev_word_best_choice_ptr) {
  Init();
  BLOCK_IT block_it(the_block_list);
  BLOCK_RES_IT block_res_it(&block_res_list);
  for (block_it.mark_cycle_pt(); !block_it.cycled_list(); block_it.forward()) {
    block_res_it.add_to_end(
        new BLOCK_RES(merge_similar_words, block_it.data()));
  }
  prev_word_best_choice = prev_word_best_choice_ptr;
}