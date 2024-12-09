void Fl::flush() {
  if (damage()) {
    damage_ = 0;
    for (Fl_X* i = Fl_X::first; i; i = i->next) {
      if (i->wait_for_expose) {damage_ = 1; continue;}
      Fl_Window* wi = i->w;
      if (!wi->visible_r()) continue;
      if (wi->damage()) {i->flush(); wi->clear_damage();}
      // destroy damage regions for windows that don't use them:
      if (i->region) {XDestroyRegion(i->region); i->region = 0;}
    }
  }
#if defined(USE_X11)
  if (fl_display) XFlush(fl_display);
#elif defined(WIN32)
  GdiFlush();
#elif defined (__APPLE_QUARTZ__)
  if (fl_gc)
    CGContextFlush(fl_gc);
#else
# error unsupported platform
#endif
}