Fl_Tree_Item *Fl_Tree_Item::next_displayed(Fl_Tree_Prefs &prefs) {
  Fl_Tree_Item *c = this;
  while ( c ) {
    if ( c->is_root() && !prefs.showroot() ) {		// on root and can't show it?
      c = c->next();					// skip ahead, try again
      continue;
    }
    if ( c->has_children() && c->is_close() ) {		// item has children and: invisible or closed?
      // Skip children, take next sibling. If none, try parent's sibling, repeat
      while ( c ) {
	Fl_Tree_Item *sib = c->next_sibling();		// get sibling
	if ( sib ) { c = sib; break; }			// Found? let outer loop test it
	c = c->parent();				// No sibling? move up tree, try parent's sibling
      }
    } else {						// has children and isn't closed, or no children
      c = c->next();					// use normal 'next'
    }
    if ( !c ) return(0);				// no more? done
    // Check all parents to be sure none are closed.
    // If closed, move up to that level and repeat until sure none are closed.
    Fl_Tree_Item *p = c->parent();
    while (1) {
      if ( !p || p->is_root() ) return(c);		// hit top? then we're displayed, return c
      if ( p->is_close() ) c = p;			// found closed parent? make it current
      p = p->parent();					// continue up tree
    }
    if ( c && c->visible() ) return(c);			// item visible? return it
  }
  return(0);						// hit end: no more items
}