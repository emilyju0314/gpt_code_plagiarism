WERD_RES *PAGE_RES_IT::start_page(bool empty_ok) {
  block_res_it.set_to_list(&page_res->block_res_list);
  block_res_it.mark_cycle_pt();
  prev_block_res = nullptr;
  prev_row_res = nullptr;
  prev_word_res = nullptr;
  block_res = nullptr;
  row_res = nullptr;
  word_res = nullptr;
  next_block_res = nullptr;
  next_row_res = nullptr;
  next_word_res = nullptr;
  internal_forward(true, empty_ok);
  return internal_forward(false, empty_ok);
}