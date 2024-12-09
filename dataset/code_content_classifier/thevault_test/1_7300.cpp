Fl_Progress::Fl_Progress(int X, int Y, int W, int H, const char* L)
: Fl_Widget(X, Y, W, H, L) {
  align(FL_ALIGN_INSIDE);
  box(FL_DOWN_BOX);
  color(FL_BACKGROUND2_COLOR, FL_YELLOW);
  minimum(0.0f);
  maximum(100.0f);
  value(0.0f);
}