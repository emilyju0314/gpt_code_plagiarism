WERD_RES *PAGE_RES_IT::forward_paragraph() {
  while (block_res == next_block_res &&
         (next_row_res != nullptr && next_row_res->row != nullptr &&
          row_res->row->para() == next_row_res->row->para())) {
    internal_forward(false, true);
  }
  return internal_forward(false, true);
}