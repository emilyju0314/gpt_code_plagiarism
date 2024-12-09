void SVPaint::Notify(const SVEvent *sv_event) {
  if (sv_event->type == SVET_CLICK) {
    ClickHandler(sv_event);
  } else if (sv_event->type == SVET_SELECTION) {
    SelectionHandler(sv_event);
  } else if (sv_event->type == SVET_MENU) {
    MenuBarHandler(sv_event);
  } else if (sv_event->type == SVET_POPUP) {
    PopupHandler(sv_event);
  }
  // throw other events away
}