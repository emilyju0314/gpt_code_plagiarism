Fl_Timer::Fl_Timer(uchar t, int X, int Y, int W, int H, const char* l)

: Fl_Widget(X, Y, W, H, l) {
  box(FL_DOWN_BOX);
  selection_color(FL_RED);
  delay = 0;
  on = 0;
  direction_ = 0;
  type(t);
  if (t == FL_HIDDEN_TIMER) clear_visible();
  if (t == FL_VALUE_TIMER) align(FL_ALIGN_LEFT);
}