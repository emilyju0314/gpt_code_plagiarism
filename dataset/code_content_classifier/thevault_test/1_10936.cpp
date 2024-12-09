void Textord::CleanupSingleRowResult(PageSegMode pageseg_mode, PAGE_RES *page_res) {
  if (PSM_LINE_FIND_ENABLED(pageseg_mode) || PSM_SPARSE(pageseg_mode)) {
    return; // No cleanup required.
  }
  PAGE_RES_IT it(page_res);
  // Find the best row, being the greatest mean word conf.
  float row_total_conf = 0.0f;
  int row_word_count = 0;
  ROW_RES *best_row = nullptr;
  float best_conf = 0.0f;
  for (it.restart_page(); it.word() != nullptr; it.forward()) {
    WERD_RES *word = it.word();
    row_total_conf += word->best_choice->certainty();
    ++row_word_count;
    if (it.next_row() != it.row()) {
      row_total_conf /= row_word_count;
      if (best_row == nullptr || best_conf < row_total_conf) {
        best_row = it.row();
        best_conf = row_total_conf;
      }
      row_total_conf = 0.0f;
      row_word_count = 0;
    }
  }
  // Now eliminate any word not in the best row.
  for (it.restart_page(); it.word() != nullptr; it.forward()) {
    if (it.row() != best_row) {
      it.DeleteCurrentWord();
    }
  }
}