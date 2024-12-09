int Fl_Menu_Item::add(
  const char *mytext,
  int sc,
  Fl_Callback *cb,	
  void *data,
  int myflags
) {
  return(insert(-1,mytext,sc,cb,data,myflags));		// -1: append
}