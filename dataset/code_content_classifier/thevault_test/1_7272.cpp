void Fl_X::q_release_context(Fl_X *x) {
  if (x && x->gc!=fl_gc) return;
  if (!fl_gc) return;
  CGContextRestoreGState(fl_gc);
  if (fl_window) {
    OSStatus err = QDEndCGContext(GetWindowPort(fl_window), &fl_gc);
    if (err!=noErr)
      fprintf(stderr, "Error %d in QDEndCGContext\n", (int)err);
  }
  fl_gc = 0;
#if defined(USE_CAIRO)
  if (Fl::cairo_autolink_context()) Fl::cairo_make_current((Fl_Window*) 0); // capture gc changes automatically to update the cairo context adequately
#endif
}