Fl_Native_File_Chooser::~Fl_Native_File_Chooser() {
  delete _file_chooser;
  _filter      = strfree(_filter);
  _parsedfilt  = strfree(_parsedfilt);
  _preset_file = strfree(_preset_file);
  _prevvalue   = strfree(_prevvalue);
  _directory   = strfree(_directory);
  _errmsg      = strfree(_errmsg);
  _old_dir     = strfree(_old_dir);
}