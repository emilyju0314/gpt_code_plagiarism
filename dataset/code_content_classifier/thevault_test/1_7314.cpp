int						// O - TRUE on success
Fl_File_Input::value(const char *str) {		// I - New string value
  damage(FL_DAMAGE_BAR);
  return Fl_Input::value(str);
}