int Fl_Menu_::clear_submenu(int index) {
  if ( index < 0 || index >= size() ) return(-1);
  if ( ! (menu_[index].flags & FL_SUBMENU) ) return(-1);
  ++index;					// advance to first item in submenu
  while ( index < size() ) {                    // keep remove()ing top item until end is reached
    if ( menu_[index].text == 0 ) break;	// end of this submenu? done
    remove(index);				// remove items/submenus
  }
  return(0);
}