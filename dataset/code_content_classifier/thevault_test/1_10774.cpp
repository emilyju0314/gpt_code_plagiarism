int ScrollView::TranslateYCoordinate(int y) {
  if (!y_axis_is_reversed_) {
    return y;
  } else {
    return y_size_ - y;
  }
}