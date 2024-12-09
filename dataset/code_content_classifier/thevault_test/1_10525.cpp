bool Tesseract::word_set_display(PAGE_RES_IT *pr_it) {
  WERD *word = pr_it->word()->word;
  word->set_display_flag(DF_BOX, word_display_mode[DF_BOX]);
  word->set_display_flag(DF_TEXT, word_display_mode[DF_TEXT]);
  word->set_display_flag(DF_POLYGONAL, word_display_mode[DF_POLYGONAL]);
  word->set_display_flag(DF_EDGE_STEP, word_display_mode[DF_EDGE_STEP]);
  word->set_display_flag(DF_BN_POLYGONAL, word_display_mode[DF_BN_POLYGONAL]);
  word->set_display_flag(DF_BLAMER, word_display_mode[DF_BLAMER]);
  return word_display(pr_it);
}