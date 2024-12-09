void ScrollView::Rectangle(int x1, int y1, int x2, int y2) {
  if (x1 == x2 && y1 == y2) {
    return; // Scrollviewer locks up.
  }
  SendMsg("drawRectangle(%d,%d,%d,%d)", x1, TranslateYCoordinate(y1), x2, TranslateYCoordinate(y2));
}