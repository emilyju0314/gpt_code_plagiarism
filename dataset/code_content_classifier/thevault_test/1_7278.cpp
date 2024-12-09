Fl_Pack::Fl_Pack(int X, int Y, int W, int H,const char *l)
: Fl_Group(X, Y, W, H, l) {
  resizable(0);
  spacing_ = 0;
  // type(VERTICAL); // already set like this
}