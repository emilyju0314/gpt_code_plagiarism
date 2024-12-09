void ScrollView::PopupItem(const char *parent, const char *name) {
  if (parent == nullptr) {
    parent = "";
  }
  SendMsg("addPopupMenuItem('%s','%s')", parent, name);
}