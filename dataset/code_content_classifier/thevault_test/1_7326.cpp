Fl_Button::Fl_Button(int X, int Y, int W, int H, const char *L)
: Fl_Widget(X,Y,W,H,L) {
  box(FL_UP_BOX);
  down_box(FL_NO_BOX);
  value_ = oldval = 0;
  shortcut_ = 0;
  set_flag(SHORTCUT_LABEL);
}