int Fl_Native_File_Chooser::show() {
  // FILTER
  if ( _parsedfilt ) {
    _file_chooser->filter(_parsedfilt);
  }

  // FILTER VALUE
  //     Set this /after/ setting the filter
  //
  _file_chooser->filter_value(_filtvalue);

  // DIRECTORY
  if ( _directory && _directory[0] ) {
    _file_chooser->directory(_directory);
  } else {
    _file_chooser->directory(_prevvalue);
  }

  // PRESET FILE
  if ( _preset_file ) {
    _file_chooser->value(_preset_file);
  }

  // OPTIONS: PREVIEW
  _file_chooser->preview( (options() & PREVIEW) ? 1 : 0);

  // OPTIONS: NEW FOLDER
  if ( options() & NEW_FOLDER )
    _file_chooser->type(_file_chooser->type() | FLTK_CHOOSER_CREATE);	// on

  // SHOW
  _file_chooser->show();

  // BLOCK WHILE BROWSER SHOWN
  while ( _file_chooser->shown() ) {
    if (_old_dir==0 || strcmp(_old_dir, _file_chooser->directory()) != 0) {
      _old_dir = strfree(_old_dir);
      _old_dir = strnew(_file_chooser->directory());
      if (!show_hidden->value()) remove_hidden_files(my_fileList);
    } else if (prev_filtervalue != _file_chooser->filter_value() ) {
      prev_filtervalue = _file_chooser->filter_value();
      if (!show_hidden->value() ) remove_hidden_files(my_fileList);
    }
    Fl::wait();
  }

  if ( _file_chooser->value() && _file_chooser->value()[0] ) {
    _prevvalue = strfree(_prevvalue);
    _prevvalue = strnew(_file_chooser->value());
    _filtvalue = _file_chooser->filter_value();	// update filter value

    // HANDLE SHOWING 'SaveAs' CONFIRM
    if ( options() & SAVEAS_CONFIRM && type() == BROWSE_SAVE_FILE ) {
      struct stat buf;
      if ( stat(_file_chooser->value(), &buf) != -1 ) {
	if ( buf.st_mode & S_IFREG ) {		// Regular file + exists?
	  if ( exist_dialog() == 0 ) {
	    return(1);
	  }
	}
      }
    }
  }

  if ( _file_chooser->count() ) return(0);
  else return(1);
}