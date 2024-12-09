void Fl_Native_File_Chooser::ClearBINF() {
  if ( _binf.pidlRoot ) {
    FreePIDL((ITEMIDLIST*)_binf.pidlRoot);
    _binf.pidlRoot = NULL;
  }
  memset((void*)&_binf, 0, sizeof(_binf));
}