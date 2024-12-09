Fl_Round_Button::Fl_Round_Button(int X,int Y,int W,int H, const char *l)
: Fl_Light_Button(X,Y,W,H,l) {
  box(FL_NO_BOX);
  down_box(FL_ROUND_DOWN_BOX);
  selection_color(FL_FOREGROUND_COLOR);
}