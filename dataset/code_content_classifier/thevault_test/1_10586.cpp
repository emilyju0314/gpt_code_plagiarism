static bool pixNearlyRectangular(Image pix, double min_fraction, double max_fraction,
                                 double max_skew_gradient, int *x_start, int *y_start,
                                 int *x_end, int *y_end) {
  ASSERT_HOST(pix != nullptr);
  *x_start = 0;
  *x_end = pixGetWidth(pix);
  *y_start = 0;
  *y_end = pixGetHeight(pix);

  uint32_t *data = pixGetData(pix);
  int wpl = pixGetWpl(pix);
  bool any_cut = false;
  bool left_done = false;
  bool right_done = false;
  bool top_done = false;
  bool bottom_done = false;
  do {
    any_cut = false;
    // Find the top/bottom edges.
    int width = *x_end - *x_start;
    int min_count = static_cast<int>(width * min_fraction);
    int max_count = static_cast<int>(width * max_fraction);
    int edge_width = static_cast<int>(width * max_skew_gradient);
    if (HScanForEdge(data, wpl, *x_start, *x_end, min_count, edge_width, max_count, *y_end, 1,
                     y_start) &&
        !top_done) {
      top_done = true;
      any_cut = true;
    }
    --(*y_end);
    if (HScanForEdge(data, wpl, *x_start, *x_end, min_count, edge_width, max_count, *y_start, -1,
                     y_end) &&
        !bottom_done) {
      bottom_done = true;
      any_cut = true;
    }
    ++(*y_end);

    // Find the left/right edges.
    int height = *y_end - *y_start;
    min_count = static_cast<int>(height * min_fraction);
    max_count = static_cast<int>(height * max_fraction);
    edge_width = static_cast<int>(height * max_skew_gradient);
    if (VScanForEdge(data, wpl, *y_start, *y_end, min_count, edge_width, max_count, *x_end, 1,
                     x_start) &&
        !left_done) {
      left_done = true;
      any_cut = true;
    }
    --(*x_end);
    if (VScanForEdge(data, wpl, *y_start, *y_end, min_count, edge_width, max_count, *x_start, -1,
                     x_end) &&
        !right_done) {
      right_done = true;
      any_cut = true;
    }
    ++(*x_end);
  } while (any_cut);

  // All edges must satisfy the condition of sharp gradient in pixel density
  // in order for the full rectangle to be present.
  return left_done && right_done && top_done && bottom_done;
}