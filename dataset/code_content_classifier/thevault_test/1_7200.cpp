void Fl_Gl_Window::swap_buffers() {
#if defined(USE_X11)
  glXSwapBuffers(fl_display, fl_xid(this));
#elif defined(WIN32)
#  if HAVE_GL_OVERLAY
  // Do not swap the overlay, to match GLX:
  BOOL ret = wglSwapLayerBuffers(Fl_X::i(this)->private_dc, WGL_SWAP_MAIN_PLANE);
  DWORD err = GetLastError();;
#  else
  SwapBuffers(Fl_X::i(this)->private_dc);
#  endif
#elif defined(__APPLE_QUARTZ__)
  if(overlay != NULL) {
    //aglSwapBuffers does not work well with overlays under cocoa
    glReadBuffer(GL_BACK);
    glDrawBuffer(GL_FRONT);
    glCopyPixels(0,0,w(),h(),GL_COLOR);
  }
  else
    aglSwapBuffers((AGLContext)context_);
#else
# error unsupported platform
#endif
}