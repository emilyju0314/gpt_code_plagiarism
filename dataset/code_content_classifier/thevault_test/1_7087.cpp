int Fl_Tree::deselect_all(Fl_Tree_Item *item, int docallback) {
  item = item ? item : first();			// NULL? use first()
  if ( ! item ) return(0);
  int count = 0;
  for ( ; item; item = next(item) ) {
    if ( item->is_selected() )
      if ( deselect(item, docallback) )
        ++count;
  }
  return(count);
}