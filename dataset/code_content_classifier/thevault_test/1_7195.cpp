HDC fl_GetDC(HWND w) {
  if (fl_gc) {
    if (w == fl_window  &&  fl_window != NULL) return fl_gc;
    if (fl_window) fl_release_dc(fl_window, fl_gc); // ReleaseDC
  }
  fl_gc = GetDC(w);
  fl_save_dc(w, fl_gc);
  fl_window = w;
  // calling GetDC seems to always reset these: (?)
  SetTextAlign(fl_gc, TA_BASELINE|TA_LEFT);
  SetBkMode(fl_gc, TRANSPARENT);

  return fl_gc;
}