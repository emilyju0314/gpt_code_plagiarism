void Fl_Gl_Window::hide_overlay() {
#if HAVE_GL_OVERLAY
#ifdef WIN32
  // nothing needs to be done?  Or should it be erased?
#else
  if (overlay && overlay!=this) ((Fl_Gl_Window*)overlay)->hide();
#endif
#endif
}