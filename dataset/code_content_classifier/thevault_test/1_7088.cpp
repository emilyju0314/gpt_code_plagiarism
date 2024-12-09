int Fl_Tree::select_only(Fl_Tree_Item *selitem, int docallback) {
  selitem = selitem ? selitem : first();	// NULL? use first()
  if ( ! selitem ) return(0);
  int changed = 0;
  for ( Fl_Tree_Item *item = first(); item; item = item->next() ) {
    if ( item == selitem ) {
      if ( item->is_selected() ) continue;	// don't count if already selected
      select(item, docallback);
      ++changed;
    } else {
      if ( item->is_selected() ) {
        deselect(item, docallback);
        ++changed;
      }
    }
  }
  return(changed);
}