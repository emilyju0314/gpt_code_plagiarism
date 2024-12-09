int Fl_Menu_::find_index(Fl_Callback *cb) const {
  for ( int t=0; t < size(); t++ )
    if (menu_[t].callback_==cb)
      return(t);
  return(-1);
}