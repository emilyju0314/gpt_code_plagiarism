Fl_Widget_Tracker::Fl_Widget_Tracker(Fl_Widget *wi) {

  wp_ = wi;
  Fl::watch_widget_pointer(wp_); // add pointer to watch list
}