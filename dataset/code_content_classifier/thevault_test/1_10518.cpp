static void display_bln_lines(ScrollView *window, ScrollView::Color colour, float scale_factor,
                              float y_offset, float minx, float maxx) {
  window->Pen(colour);
  window->Line(minx, y_offset + scale_factor * DESC_HEIGHT, maxx,
               y_offset + scale_factor * DESC_HEIGHT);
  window->Line(minx, y_offset + scale_factor * BL_HEIGHT, maxx,
               y_offset + scale_factor * BL_HEIGHT);
  window->Line(minx, y_offset + scale_factor * X_HEIGHT, maxx, y_offset + scale_factor * X_HEIGHT);
  window->Line(minx, y_offset + scale_factor * ASC_HEIGHT, maxx,
               y_offset + scale_factor * ASC_HEIGHT);
}