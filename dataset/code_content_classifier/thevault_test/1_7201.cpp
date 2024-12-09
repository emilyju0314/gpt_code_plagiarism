int Fl_Gl_Window::handle(int event) 
{
#if (__APPLE_QUARTZ__)
  if (event==FL_HIDE) {
    // if we are not hidden, just the parent was hidden, so we must throw away the context
    if (!visible_r())
      context(0); // remove context wthout setting the hidden flags
  }
  if (event==FL_SHOW) {
    // if we are not hidden, just the parent was shown, so we must create a new context
    if (visible_r())
      show(); //
  }
#endif
  return Fl_Window::handle(event);
}