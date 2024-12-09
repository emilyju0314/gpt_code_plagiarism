void Fl::add_handler(Fl_Event_Handler ha) {
  handler_link *l = new handler_link;
  l->handle = ha;
  l->next = handlers;
  handlers = l;
}