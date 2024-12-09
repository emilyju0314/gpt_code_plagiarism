void Fl_Tree::vposition(int pos) {
  if (pos < 0) pos = 0;
  if (pos > _vscroll->maximum()) pos = (int)_vscroll->maximum();
  if (pos == _vscroll->value()) return;
  _vscroll->value(pos);
  redraw();
}