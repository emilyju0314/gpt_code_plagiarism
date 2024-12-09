bool Tesseract::word_bln_display(PAGE_RES_IT *pr_it) {
  WERD_RES *word_res = pr_it->word();
  if (word_res->chopped_word == nullptr) {
    // Setup word normalization parameters.
    word_res->SetupForRecognition(unicharset, this, BestPix(), tessedit_ocr_engine_mode, nullptr,
                                  classify_bln_numeric_mode, textord_use_cjk_fp_model,
                                  poly_allow_detailed_fx, pr_it->row()->row, pr_it->block()->block);
  }
  bln_word_window_handle()->Clear();
  display_bln_lines(bln_word_window_handle(), ScrollView::CYAN, 1.0, 0.0f, -1000.0f, 1000.0f);
  C_BLOB_IT it(word_res->word->cblob_list());
  ScrollView::Color color = WERD::NextColor(ScrollView::BLACK);
  for (it.mark_cycle_pt(); !it.cycled_list(); it.forward()) {
    it.data()->plot_normed(word_res->denorm, color, ScrollView::BROWN, bln_word_window_handle());
    color = WERD::NextColor(color);
  }
  bln_word_window_handle()->Update();
  return true;
}