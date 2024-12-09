void Fl::copy(const char *stuff, int len, int clipboard) {
  if (!stuff || len<0) return;
  if (len+1 > fl_selection_buffer_length[clipboard]) {
    delete[] fl_selection_buffer[clipboard];
    fl_selection_buffer[clipboard] = new char[len+100];
    fl_selection_buffer_length[clipboard] = len+100;
  }
  memcpy(fl_selection_buffer[clipboard], stuff, len);
  fl_selection_buffer[clipboard][len] = 0; // needed for direct paste
  fl_selection_length[clipboard] = len;
  if (clipboard) {
#ifdef USE_PASTEBOARD
    // FIXME no error checking done yet!
    allocatePasteboard();
    OSStatus err = PasteboardClear(myPasteboard);
    if (err!=noErr) return; // clear did not work, maybe not owner of clipboard.
    PasteboardSynchronize(myPasteboard);
    CFDataRef text = CFDataCreate(kCFAllocatorDefault, (UInt8*)fl_selection_buffer[1], len);
    if (text==NULL) return; // there was a pb creating the object, abort.
    err=PasteboardPutItemFlavor(myPasteboard, (PasteboardItemID)1, CFSTR("public.utf8-plain-text"), text, 0);
    CFRelease(text);
#else
    OSStatus err = ClearCurrentScrap(); // whatever happens we should clear the current scrap.
    if(err!=noErr) {myScrap=0; return;} // don't get current scrap if a prev err occured. 
    err = GetCurrentScrap( &myScrap );
    if ( err != noErr ) {
      myScrap = 0;
      return;
    }
    // Previous version changed \n to \r before sending the text, but I would
    // prefer to leave the local buffer alone, so a copied buffer may be
    // needed. Check to see if this is necessary on OS/X.
    PutScrapFlavor( myScrap, kScrapFlavorTypeText, 0,
		    len, fl_selection_buffer[1] );
#endif
  }
}