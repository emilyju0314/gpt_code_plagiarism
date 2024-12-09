void ScrollView::SetVisible(bool visible) {
  if (visible) {
    SendMsg("setVisible(true)");
  } else {
    SendMsg("setVisible(false)");
  }
}