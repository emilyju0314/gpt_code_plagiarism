void Fl_Native_File_Chooser::filter(const char *val) {
  _filter = strfree(_filter);
  clear_filters();
  if ( val ) {
    _filter = strnew(val);
    parse_filter(_filter);
  }
  add_filter("All Files", "*.*");	// always include 'all files' option

#ifdef DEBUG
  nullprint(_parsedfilt);
#endif /*DEBUG*/
}