void Fl_Tree::set_item_focus(Fl_Tree_Item *item) {
  if ( _item_focus != item ) {		// changed?
    _item_focus = item;			// update
    if ( visible_focus() ) redraw();	// redraw to update focus box
  }
}