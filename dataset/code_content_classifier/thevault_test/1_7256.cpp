static OSErr QuitAppleEventHandler( const AppleEvent *appleEvt, AppleEvent* reply, UInt32 refcon )
{
  fl_lock_function();

  while ( Fl_X::first ) {
    Fl_X *x = Fl_X::first;
    Fl::handle( FL_CLOSE, x->w );
    if ( Fl_X::first == x ) {
      fl_unlock_function();
      return noErr; // FLTK has not close all windows, so we return to the main program now
    }
  }

  fl_unlock_function();

  return noErr;
}