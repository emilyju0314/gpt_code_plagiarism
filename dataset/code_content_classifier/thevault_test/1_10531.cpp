void ROW::recalc_bounding_box() { // recalculate BB
  WERD *word;                     // current word
  WERD_IT it = &words;            // words of ROW
  int16_t left;                   // of word
  int16_t prev_left;              // old left

  if (!it.empty()) {
    word = it.data();
    prev_left = word->bounding_box().left();
    it.forward();
    while (!it.at_first()) {
      word = it.data();
      left = word->bounding_box().left();
      if (left < prev_left) {
        it.move_to_first();
        // words in BB order
        it.sort(word_comparator);
        break;
      }
      prev_left = left;
      it.forward();
    }
  }
  for (it.mark_cycle_pt(); !it.cycled_list(); it.forward()) {
    word = it.data();
    if (it.at_first()) {
      word->set_flag(W_BOL, true);
    } else {
      // not start of line
      word->set_flag(W_BOL, false);
    }
    if (it.at_last()) {
      word->set_flag(W_EOL, true);
    } else {
      // not end of line
      word->set_flag(W_EOL, false);
    }
    // extend BB as reqd
    bound_box += word->bounding_box();
  }
}