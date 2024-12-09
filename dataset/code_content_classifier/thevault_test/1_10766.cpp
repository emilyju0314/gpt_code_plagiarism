void ScrollView::MenuItem(const char *parent, const char *name) {
  if (parent == nullptr) {
    parent = "";
  }
  SendMsg("addMenuBarItem('%s','%s')", parent, name);
}