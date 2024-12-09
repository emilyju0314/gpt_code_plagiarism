void WERD::plot(ScrollView *window) {
  ScrollView::Color colour = FIRST_COLOUR;
  C_BLOB_IT it = &cblobs;
  for (it.mark_cycle_pt(); !it.cycled_list(); it.forward()) {
    it.data()->plot(window, colour, CHILD_COLOUR);
    colour = NextColor(colour);
  }
  plot_rej_blobs(window);
}