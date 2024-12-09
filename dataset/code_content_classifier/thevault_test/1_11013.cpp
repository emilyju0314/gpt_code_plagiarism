void PAGE_RES_IT::MakeCurrentWordFuzzy() {
  WERD *real_word = word_res->word;
  if (!real_word->flag(W_FUZZY_SP) && !real_word->flag(W_FUZZY_NON)) {
    real_word->set_flag(W_FUZZY_SP, true);
    if (word_res->combination) {
      // The next word should be the corresponding part of combo, but we have
      // already stepped past it, so find it by search.
      WERD_RES_IT wr_it(&row()->word_res_list);
      for (wr_it.mark_cycle_pt();
           !wr_it.cycled_list() && wr_it.data() != word_res; wr_it.forward()) {
      }
      wr_it.forward();
      ASSERT_HOST(wr_it.data()->part_of_combo);
      real_word = wr_it.data()->word;
      ASSERT_HOST(!real_word->flag(W_FUZZY_SP) &&
                  !real_word->flag(W_FUZZY_NON));
      real_word->set_flag(W_FUZZY_SP, true);
    }
  }
}