void
Fl_Widget::do_callback(Fl_Widget* o,void* arg) {
  Fl_Widget_Tracker wp(this);
  callback_(o,arg);
  if (wp.deleted()) return;
  if (callback_ != default_callback)
    clear_changed();
}