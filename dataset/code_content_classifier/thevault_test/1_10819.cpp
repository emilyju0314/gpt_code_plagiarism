ScrollView::Color WERD::NextColor(ScrollView::Color colour) {
  auto next = static_cast<ScrollView::Color>(colour + 1);
  if (next >= LAST_COLOUR || next < FIRST_COLOUR) {
    next = FIRST_COLOUR;
  }
  return next;
}