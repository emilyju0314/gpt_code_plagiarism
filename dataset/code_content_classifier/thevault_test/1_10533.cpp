void ROW::plot(        // draw it
    ScrollView *window // window to draw in
) {
  WERD *word;          // current word
  WERD_IT it = &words; // words of ROW

  for (it.mark_cycle_pt(); !it.cycled_list(); it.forward()) {
    word = it.data();
    word->plot(window); // in rainbow colours
  }
}