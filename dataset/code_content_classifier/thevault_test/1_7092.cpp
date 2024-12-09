void Fl_Tree::show_item_bottom(Fl_Tree_Item *item) {
  item = item ? item : first();
  if ( ! item ) return;
  show_item(item, h() - item->h());
}