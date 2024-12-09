void Fl_Gl_Window::make_current() {
//  puts("Fl_Gl_Window::make_current()");
//  printf("make_current: context_=%p\n", context_);
  if (!context_) {
    mode_ &= ~NON_LOCAL_CONTEXT;
    context_ = fl_create_gl_context(this, g);
    valid(0);
    context_valid(0);
  }
  fl_set_gl_context(this, context_);

#ifdef __APPLE__
  // Set the buffer rectangle here, since in resize() we won't have the
  // correct parent window size to work with...
  GLint xywh[4];

  if (window()) {
    xywh[0] = x();
    xywh[1] = window()->h() - y() - h();
  } else {
    xywh[0] = 0;
    xywh[1] = 0;
  }

  xywh[2] = w();
  xywh[3] = h();

  aglSetInteger(context_, AGL_BUFFER_RECT, xywh);
  aglEnable(context_, AGL_BUFFER_RECT);
//  printf("make_current: xywh=[%d %d %d %d]\n", xywh[0], xywh[1], xywh[2], xywh[3]);
#endif // __APPLE__

#if defined(WIN32) && USE_COLORMAP
  if (fl_palette) {
    fl_GetDC(fl_xid(this));
    SelectPalette(fl_gc, fl_palette, FALSE);
    RealizePalette(fl_gc);
  }
#endif // USE_COLORMAP
  if (mode_ & FL_FAKE_SINGLE) {
    glDrawBuffer(GL_FRONT);
    glReadBuffer(GL_FRONT);
  }
  current_ = this;
}