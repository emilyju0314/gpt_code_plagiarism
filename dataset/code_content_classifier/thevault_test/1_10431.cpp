static void reverse_outline_list(C_OUTLINE_LIST *list) {
  C_OUTLINE_IT it = list; // iterator

  for (it.mark_cycle_pt(); !it.cycled_list(); it.forward()) {
    C_OUTLINE *outline = it.data();
    outline->reverse(); // reverse it
    outline->set_flag(COUT_INVERSE, true);
    if (!outline->child()->empty()) {
      reverse_outline_list(outline->child());
    }
  }
}