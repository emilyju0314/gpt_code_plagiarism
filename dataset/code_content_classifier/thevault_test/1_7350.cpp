void Fl_Tree_Item::open() {
  _open = 1;
  // Tell children to show() their widgets
  for ( int t=0; t<_children.total(); t++ ) {
    _children[t]->show_widgets();
  }
}