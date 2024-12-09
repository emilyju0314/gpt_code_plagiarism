void ScrollView::MenuItem(const char *parent, const char *name, int cmdEvent, bool flag) {
  if (parent == nullptr) {
    parent = "";
  }
  if (flag) {
    SendMsg("addMenuBarItem('%s','%s',%d,true)", parent, name, cmdEvent);
  } else {
    SendMsg("addMenuBarItem('%s','%s',%d,false)", parent, name, cmdEvent);
  }
}