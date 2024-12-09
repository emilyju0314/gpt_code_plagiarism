void Fl_Native_File_Chooser::FreePIDL(ITEMIDLIST *pidl) {
  IMalloc *imalloc = NULL;
  if ( SUCCEEDED(SHGetMalloc(&imalloc)) ) {
    imalloc->Free(pidl);
    imalloc->Release();
    imalloc = NULL;
  }
}