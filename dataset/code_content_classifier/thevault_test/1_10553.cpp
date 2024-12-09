void OSResults::print_scores(void) const {
  for (int i = 0; i < 4; ++i) {
    tprintf("Orientation id #%d", i);
    print_scores(i);
  }
}