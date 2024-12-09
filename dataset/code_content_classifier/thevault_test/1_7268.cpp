void Fl_Window::label(const char *name,const char */*iname*/) {
  Fl_Widget::label(name);

  if (shown() || i) {
    q_set_window_title(fl_xid(this), name);
  }
}