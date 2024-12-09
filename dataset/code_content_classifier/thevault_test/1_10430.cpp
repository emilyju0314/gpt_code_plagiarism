static void plot_normed_outline_list(const DENORM &denorm, C_OUTLINE_LIST *list,
                                     ScrollView::Color colour, ScrollView::Color child_colour,
                                     ScrollView *window) {
  C_OUTLINE_IT it(list);
  for (it.mark_cycle_pt(); !it.cycled_list(); it.forward()) {
    C_OUTLINE *outline = it.data();
    outline->plot_normed(denorm, colour, window);
    if (!outline->child()->empty()) {
      plot_normed_outline_list(denorm, outline->child(), child_colour, child_colour, window);
    }
  }
}