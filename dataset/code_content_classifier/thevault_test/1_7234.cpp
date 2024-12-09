bool Fl::option(Fl_Option o)
{
  if (!options_read_) {
    int tmp;
    { // first, read the system wide preferences
      Fl_Preferences prefs(Fl_Preferences::SYSTEM, "fltk.org", "fltk");
      Fl_Preferences opt(prefs, "options");
      prefs.get("ArrowFocus", tmp, 0); options_[OPTION_ARROW_FOCUS] = tmp;
      prefs.get("NativeFilechooser", tmp, 0); options_[OPTION_NATIVE_FILECHOOSER] = tmp;
    }
    { // next, check the user preferences
      Fl_Preferences prefs(Fl_Preferences::USER, "fltk.org", "fltk");
      Fl_Preferences opt(prefs, "options");
      prefs.get("ArrowFocus", tmp, 0); options_[OPTION_ARROW_FOCUS] = tmp;
      prefs.get("NativeFilechooser", tmp, 0); options_[OPTION_NATIVE_FILECHOOSER] = tmp;
    }
    { // now, if the developer has registered this app, we could as for per-application preferences
    }
    options_read_ = 1;
  }
  if (o<0 || o>=OPTION_LAST) 
    return false;
  return (bool)options_[o];
}