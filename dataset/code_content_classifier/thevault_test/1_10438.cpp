int32_t C_BLOB::count_transitions( // area
    int32_t threshold              // on size
) {
  C_OUTLINE_IT it = &outlines; // outlines of blob
  int32_t total = 0;           // total area

  for (it.mark_cycle_pt(); !it.cycled_list(); it.forward()) {
    C_OUTLINE *outline = it.data();
    total += outline->count_transitions(threshold);
  }
  return total;
}