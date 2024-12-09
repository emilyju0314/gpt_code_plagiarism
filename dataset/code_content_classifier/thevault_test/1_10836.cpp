bool IntGrid::RectMostlyOverThreshold(const TBOX &rect, int threshold) const {
  int min_x, min_y, max_x, max_y;
  GridCoords(rect.left(), rect.bottom(), &min_x, &min_y);
  GridCoords(rect.right(), rect.top(), &max_x, &max_y);
  int total_area = 0;
  for (int y = min_y; y <= max_y; ++y) {
    for (int x = min_x; x <= max_x; ++x) {
      int value = GridCellValue(x, y);
      if (value > threshold) {
        TBOX cell_box(x * gridsize_, y * gridsize_, (x + 1) * gridsize_, (y + 1) * gridsize_);
        cell_box &= rect; // This is in-place box intersection.
        total_area += cell_box.area();
      }
    }
  }
  return total_area * 2 > rect.area();
}