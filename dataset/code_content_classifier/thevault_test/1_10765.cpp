void ScrollView::MenuItem(const char *parent, const char *name, int cmdEvent) {
  if (parent == nullptr) {
    parent = "";
  }
  SendMsg("addMenuBarItem('%s','%s',%d)", parent, name, cmdEvent);
}