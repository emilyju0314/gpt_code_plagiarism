void ScrollView::AddMessage(const char *message) {
  char form[kMaxMsgSize];
  snprintf(form, sizeof(form), "w%u:%s", window_id_, message);

  char *esc = AddEscapeChars(form);
  SendMsg("addMessage(\"%s\")", esc);
  delete[] esc;
}