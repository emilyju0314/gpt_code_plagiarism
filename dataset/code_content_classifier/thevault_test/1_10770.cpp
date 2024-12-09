char *ScrollView::ShowInputDialog(const char *msg) {
  SendMsg("showInputDialog(\"%s\")", msg);
  SVEvent *ev;
  // wait till an input event (all others are thrown away)
  ev = AwaitEvent(SVET_INPUT);
  char *p = new char[strlen(ev->parameter) + 1];
  strcpy(p, ev->parameter);
  delete ev;
  return p;
}