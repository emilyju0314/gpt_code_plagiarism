int Fl_Menu_::find_index(const char *pathname) const {
  char menupath[1024] = "";	// File/Export
  for ( int t=0; t < size(); t++ ) {
    Fl_Menu_Item *m = menu_ + t;
    if (m->flags&FL_SUBMENU) {
      // IT'S A SUBMENU
      // we do not support searches through FL_SUBMENU_POINTER links
      if (menupath[0]) strlcat(menupath, "/", sizeof(menupath));
      strlcat(menupath, m->label(), sizeof(menupath));
      if (!strcmp(menupath, pathname)) return(t);
    } else {
      if (!m->label()) {
	// END OF SUBMENU? Pop back one level.
	char *ss = strrchr(menupath, '/');
	if ( ss ) *ss = 0;
	else menupath[0] = '\0';
	continue;
      }
      // IT'S A MENU ITEM
      char itempath[1024];	// eg. Edit/Copy
      strcpy(itempath, menupath);
      if (itempath[0]) strlcat(itempath, "/", sizeof(itempath));
      strlcat(itempath, m->label(), sizeof(itempath));
      if (!strcmp(itempath, pathname)) return(t);
    }
  }
  return(-1);
}