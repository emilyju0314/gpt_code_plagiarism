const Fl_Menu_Item * Fl_Menu_::find_item(Fl_Callback *cb) {
  for ( int t=0; t < size(); t++ ) {
    const Fl_Menu_Item *m = menu_ + t;
    if (m->callback_==cb) {
      return m;
    }
  }
  return (const Fl_Menu_Item *)0;
}