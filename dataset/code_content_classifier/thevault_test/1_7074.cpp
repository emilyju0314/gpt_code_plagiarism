int Fl_Choice::value(const Fl_Menu_Item *v) {
  if (!Fl_Menu_::value(v)) return 0;
  redraw();
  return 1;
}