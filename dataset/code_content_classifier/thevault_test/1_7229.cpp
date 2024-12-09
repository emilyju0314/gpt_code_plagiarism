static int send(int event, Fl_Widget* to, Fl_Window* window) {
  int dx, dy;
  int old_event = Fl::e_number;
  if (window) {
    dx = window->x();
    dy = window->y();
  } else {
    dx = dy = 0;
  }
  for (const Fl_Widget* w = to; w; w = w->parent())
    if (w->type()>=FL_WINDOW) {dx -= w->x(); dy -= w->y();}
  int save_x = Fl::e_x; Fl::e_x += dx;
  int save_y = Fl::e_y; Fl::e_y += dy;
  int ret = to->handle(Fl::e_number = event);
  Fl::e_number = old_event;
  Fl::e_y = save_y;
  Fl::e_x = save_x;
  return ret;
}