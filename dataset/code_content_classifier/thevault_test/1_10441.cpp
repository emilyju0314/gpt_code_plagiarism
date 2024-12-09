int16_t C_BLOB::EstimateBaselinePosition() {
  TBOX box = bounding_box();
  int left = box.left();
  int width = box.width();
  int bottom = box.bottom();
  if (outlines.empty() || perimeter() > width * kMaxPerimeterWidthRatio) {
    return bottom; // This is only for non-CJK blobs.
  }
  // Get the minimum y coordinate at each x-coordinate.
  std::vector<int> y_mins(width + 1, box.top());
  C_OUTLINE_IT it(&outlines);
  for (it.mark_cycle_pt(); !it.cycled_list(); it.forward()) {
    C_OUTLINE *outline = it.data();
    ICOORD pos = outline->start_pos();
    for (int s = 0; s < outline->pathlength(); ++s) {
      if (pos.y() < y_mins[pos.x() - left]) {
        y_mins[pos.x() - left] = pos.y();
      }
      pos += outline->step(s);
    }
  }
  // Find the total extent of the bottom or bottom + 1.
  int bottom_extent = 0;
  for (int x = 0; x <= width; ++x) {
    if (y_mins[x] == bottom || y_mins[x] == bottom + 1) {
      ++bottom_extent;
    }
  }
  // Find the lowest run longer than the bottom extent that is not the bottom.
  int best_min = box.top();
  int prev_run = 0;
  int prev_y = box.top();
  int prev_prev_y = box.top();
  for (int x = 0; x < width; x += prev_run) {
    // Find the length of the current run.
    int y_at_x = y_mins[x];
    int run = 1;
    while (x + run <= width && y_mins[x + run] == y_at_x) {
      ++run;
    }
    if (y_at_x > bottom + 1) {
      // Possible contender.
      int total_run = run;
      // Find extent of current value or +1 to the right of x.
      while (x + total_run <= width &&
             (y_mins[x + total_run] == y_at_x || y_mins[x + total_run] == y_at_x + 1)) {
        ++total_run;
      }
      // At least one end has to be higher so it is not a local max.
      if (prev_prev_y > y_at_x + 1 || x + total_run > width || y_mins[x + total_run] > y_at_x + 1) {
        // If the prev_run is at y + 1, then we can add that too. There cannot
        // be a suitable run at y before that or we would have found it already.
        if (prev_run > 0 && prev_y == y_at_x + 1) {
          total_run += prev_run;
        }
        if (total_run > bottom_extent && y_at_x < best_min) {
          best_min = y_at_x;
        }
      }
    }
    prev_run = run;
    prev_prev_y = prev_y;
    prev_y = y_at_x;
  }
  return best_min == box.top() ? bottom : best_min;
}