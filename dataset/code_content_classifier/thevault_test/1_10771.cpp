void ScrollView::ZoomToRectangle(int x1, int y1, int x2, int y2) {
  y1 = TranslateYCoordinate(y1);
  y2 = TranslateYCoordinate(y2);
  SendMsg("zoomRectangle(%d,%d,%d,%d)", std::min(x1, x2), std::min(y1, y2), std::max(x1, x2),
          std::max(y1, y2));
}