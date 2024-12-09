bool IntGrid::AnyZeroInRect(const TBOX &rect) const {
  int min_x, min_y, max_x, max_y;
  GridCoords(rect.left(), rect.bottom(), &min_x, &min_y);
  GridCoords(rect.right(), rect.top(), &max_x, &max_y);
  for (int y = min_y; y <= max_y; ++y) {
    for (int x = min_x; x <= max_x; ++x) {
      if (GridCellValue(x, y) == 0) {
        return true;
      }
    }
  }
  return false;
}