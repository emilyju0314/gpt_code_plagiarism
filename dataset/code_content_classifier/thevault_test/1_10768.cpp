void ScrollView::PopupItem(const char *parent, const char *name, int cmdEvent, const char *value,
                           const char *desc) {
  if (parent == nullptr) {
    parent = "";
  }
  char *esc = AddEscapeChars(value);
  char *esc2 = AddEscapeChars(desc);
  SendMsg("addPopupMenuItem('%s','%s',%d,'%s','%s')", parent, name, cmdEvent, esc, esc2);
  delete[] esc;
  delete[] esc2;
}