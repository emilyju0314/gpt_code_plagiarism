int Fl_Window::handle(int ev)
{
  if (parent()) {
    switch (ev) {
    case FL_SHOW:
      if (!shown()) show();
      else {
#if defined(USE_X11) || defined(WIN32)
        XMapWindow(fl_display, fl_xid(this)); // extra map calls are harmless
#elif defined(__APPLE_QUARTZ__)
        MacMapWindow(this, i->xid);
#else
# error unsupported platform
#endif // __APPLE__
      }
      break;
    case FL_HIDE:
      if (shown()) {
	// Find what really turned invisible, if is was a parent window
	// we do nothing.  We need to avoid unnecessary unmap calls
	// because they cause the display to blink when the parent is
	// remapped.  However if this or any intermediate non-window
	// widget has really had hide() called directly on it, we must
	// unmap because when the parent window is remapped we don't
	// want to reappear.
	if (visible()) {
	 Fl_Widget* p = parent(); for (;p->visible();p = p->parent()) {}
	 if (p->type() >= FL_WINDOW) break; // don't do the unmap
	}
#if defined(USE_X11) || defined(WIN32)
	XUnmapWindow(fl_display, fl_xid(this));
#elif defined(__APPLE_QUARTZ__)
	MacUnmapWindow(this, i->xid);
#else
# error platform unsupported
#endif
      }
      break;
    }
//  } else if (ev == FL_FOCUS || ev == FL_UNFOCUS) {
//    Fl_Tooltip::exit(Fl_Tooltip::current());
  }

  return Fl_Group::handle(ev);
}