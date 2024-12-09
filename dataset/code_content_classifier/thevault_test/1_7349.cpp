Fl_Tree_Item *Fl_Tree_Item::add(const Fl_Tree_Prefs &prefs, char **arr) {
  int t = find_child(*arr);
  Fl_Tree_Item *item;
  if ( t == -1 ) {
    item = (Fl_Tree_Item*)add(prefs, *arr);
  } else {
    item = (Fl_Tree_Item*)child(t);
  }
  if ( *(arr+1) ) {		// descend?
    return(item->add(prefs, arr+1));
  } else {
    return(item);		// end? done
  }
}