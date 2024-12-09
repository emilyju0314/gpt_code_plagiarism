int Fl_Choice::value(int v) {
  if (v == -1) return value((const Fl_Menu_Item *)0);
  if (v < 0 || v >= (size() - 1)) return 0;
  if (!Fl_Menu_::value(v)) return 0;
  redraw();
  return 1;
}