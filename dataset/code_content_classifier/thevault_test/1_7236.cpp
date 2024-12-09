Fl_Adjuster::Fl_Adjuster(int X, int Y, int W, int H, const char* l)
  : Fl_Valuator(X, Y, W, H, l) {
  box(FL_UP_BOX);
  step(1, 10000);
  selection_color(FL_SELECTION_COLOR);
  drag = 0;
  soft_ = 1;
}