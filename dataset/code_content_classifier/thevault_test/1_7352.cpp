Fl_Tree_Item *Fl_Tree_Item::prev() {
  Fl_Tree_Item *p=parent();		// start with parent
  if ( ! p ) return(0);			// hit root? done
  int t = p->find_child(this);		// find our position in parent's children[] array
  if ( --t == -1 ) {	 		// are we first child?
    return(p);				// return immediate parent
  }
  p = p->child(t);			// take parent's previous child
  while ( p->has_children() ) {		// has children?
    p = p->child(p->children()-1);	// take last child
  }
  return(p);
}