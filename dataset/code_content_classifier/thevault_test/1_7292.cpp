Fl_Native_File_Chooser::Fl_Native_File_Chooser(int val) {
  //// CANT USE THIS -- MESSES UP LINKING/CREATES DEPENDENCY ON fltk_images.
  //// Have app call this from main() instead.
  ////
  ////  static int init = 0;		// 'first time' initialize flag
  ////  if ( init == 0 ) {
  ////    // Initialize when instanced for first time
  ////    Fl_File_Icon::load_system_icons();
  ////    init = 1;
  ////  }
  _btype       = val;
  _options     = NO_OPTIONS;
  _filter      = NULL;
  _filtvalue   = 0;
  _parsedfilt  = NULL;
  _preset_file = NULL;
  _prevvalue   = NULL;
  _directory   = NULL;
  _errmsg      = NULL;
  _file_chooser = new Fl_File_Chooser(NULL, NULL, 0, NULL);
  type(val);			// do this after _file_chooser created
  _nfilters    = 0;

  // Added by MG
  Fl_Button *b = _file_chooser->previewButton;
  Fl_Window *w = b->window();
  Fl_Group::current(w);		// adds a "Show hidden files" check button in _file_chooser's window
  show_hidden = new Fl_Check_Button(b->x() + b->w() + 10, b->y(), 145, b->h(), "Show hidden files");
  show_hidden->callback((Fl_Callback*)show_hidden_cb, this);
  my_fileList = _file_chooser->browser();
  _old_dir = 0;						// to detect directory changes
  prev_filtervalue = _file_chooser->filter_value();	// to detect filter changes
}