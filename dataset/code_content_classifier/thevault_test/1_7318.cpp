Fl_Slider::Fl_Slider(uchar t, int X, int Y, int W, int H, const char* L)
  : Fl_Valuator(X, Y, W, H, L) {
  type(t);
  box(t==FL_HOR_NICE_SLIDER || t==FL_VERT_NICE_SLIDER ?
      FL_FLAT_BOX : FL_DOWN_BOX);
  _Fl_Slider();
}