void Fl_Tree::show_item_middle(Fl_Tree_Item *item) {
  item = item ? item : first();
  if ( ! item ) return;
  show_item(item, h()/2 - item->h()/2);
}