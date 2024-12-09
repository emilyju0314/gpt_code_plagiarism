int32_t C_BLOB::perimeter() {
  C_OUTLINE_IT it = &outlines; // outlines of blob
  int32_t total = 0;           // total perimeter

  for (it.mark_cycle_pt(); !it.cycled_list(); it.forward()) {
    C_OUTLINE *outline = it.data();
    total += outline->perimeter();
  }
  return total;
}