void C_BLOB::CheckInverseFlagAndDirection() {
  C_OUTLINE_IT ol_it(&outlines);
  for (ol_it.mark_cycle_pt(); !ol_it.cycled_list(); ol_it.forward()) {
    C_OUTLINE *outline = ol_it.data();
    if (outline->turn_direction() < 0) {
      outline->reverse();
      reverse_outline_list(outline->child());
      outline->set_flag(COUT_INVERSE, true);
    } else {
      outline->set_flag(COUT_INVERSE, false);
    }
  }
}