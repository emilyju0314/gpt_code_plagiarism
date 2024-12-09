void Fl_Tree::show_item_top(Fl_Tree_Item *item) {
  item = item ? item : first();
  if ( ! item ) return;
  show_item(item, 0);
}