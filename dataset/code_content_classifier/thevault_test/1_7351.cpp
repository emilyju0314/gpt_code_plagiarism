void Fl_Tree_Item::close() {
  _open = 0;
  // Tell children to hide() their widgets
  for ( int t=0; t<_children.total(); t++ ) {
    _children[t]->hide_widgets();
  }
}