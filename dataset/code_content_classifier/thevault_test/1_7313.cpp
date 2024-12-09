int						// O - TRUE on success
Fl_File_Input::value(const char *str,		// I - New string value
                     int        len) {		// I - Length of value
  damage(FL_DAMAGE_BAR);
  return Fl_Input::value(str,len);
}