char *					// O - Filename or NULL
fl_file_chooser(const char *message,	// I - Message in titlebar
                const char *pat,	// I - Filename pattern
		const char *fname,	// I - Initial filename selection
		int        relative) {	// I - 0 for absolute path
  static char	retname[1024];		// Returned filename

  if (!fc) {
    if (!fname || !*fname) fname = ".";

    fc = new Fl_File_Chooser(fname, pat, Fl_File_Chooser::CREATE, message);
    fc->callback(callback, 0);
  } else {
    fc->type(Fl_File_Chooser::CREATE);
    // see, if we use the same pattern between calls
    char same_pattern = 0;
    const char *fcf = fc->filter();
    if ( fcf && pat && strcmp(fcf, pat)==0)
      same_pattern = 1;
    else if ( (fcf==0L || *fcf==0) && (pat==0L || *pat==0) )
      same_pattern = 1;
    // now set the pattern to the new pattern (even if they are the same)
    fc->filter(pat);
    fc->label(message);

    if (!fname) { // null pointer reuses same filename if pattern didn't change
      if (!same_pattern && fc->value()) {
	// if pattern is different, remove name but leave old directory:
	strlcpy(retname, fc->value(), sizeof(retname));

	char *p = strrchr(retname, '/');

        if (p) {
	  // If the filename is "/foo", then the directory will be "/", not
	  // ""...
	  if (p == retname)
	    retname[1] = '\0';
	  else
	    *p = '\0';
	}
	// Set the directory...
	fc->value(retname);
      } else {
        // re-use the previously selected name
      }
    } else if (!*fname) { // empty filename reuses directory with empty name
      const char *fcv = fc->value();
      if (fcv) 
        strlcpy(retname, fc->value(), sizeof(retname));
      else 
        *retname = 0;
      const char *n = fl_filename_name(retname);
      if (n) *((char*)n) = 0;
      fc->value("");
      fc->directory(retname);
    } else {
       fc->value(fname);
    }
  }

  fc->ok_label(current_label);
  fc->show();

  while (fc->shown())
    Fl::wait();

  if (fc->value() && relative) {
    fl_filename_relative(retname, sizeof(retname), fc->value());

    return retname;
  } else if (fc->value()) return (char *)fc->value();
  else return 0;
}