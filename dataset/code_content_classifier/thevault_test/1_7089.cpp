void Fl_Tree::show_item(Fl_Tree_Item *item, int yoff) {
  if ( ! item ) return;
  int newval = item->y() - y() - yoff + (int)_vscroll->value();
  if ( newval < _vscroll->minimum() ) newval = (int)_vscroll->minimum();
  if ( newval > _vscroll->maximum() ) newval = (int)_vscroll->maximum();
  _vscroll->value(newval);
  redraw();
}