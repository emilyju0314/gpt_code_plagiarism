void ScrollView::Line(int x1, int y1, int x2, int y2) {
  if (!points_->xcoords.empty() && x1 == points_->xcoords.back() &&
      TranslateYCoordinate(y1) == points_->ycoords.back()) {
    // We are already at x1, y1, so just draw to x2, y2.
    DrawTo(x2, y2);
  } else if (!points_->xcoords.empty() && x2 == points_->xcoords.back() &&
             TranslateYCoordinate(y2) == points_->ycoords.back()) {
    // We are already at x2, y2, so just draw to x1, y1.
    DrawTo(x1, y1);
  } else {
    // This is a new line.
    SetCursor(x1, y1);
    DrawTo(x2, y2);
  }
}