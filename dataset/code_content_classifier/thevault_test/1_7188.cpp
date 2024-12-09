void fl_text_extents(const char *c, int n, int &dx, int &dy, int &w, int &h) {
  if (!fl_fontsize) {
    w = 0; h = 0;
    dx = dy = 0;
    return;
  }
  static const MAT2 matrix = { { 0, 1 }, { 0, 0 }, { 0, 0 }, { 0, 1 } };
  GLYPHMETRICS metrics;
  int maxw = 0, maxh = 0, dh;
  int minx = 0, miny = -999999;
  unsigned len = 0, idx = 0;
  HWND hWnd = 0;

  // Have we loaded the GetGlyphIndicesW function yet?
  if (have_loaded_GetGlyphIndices == 0) {
    GetGlyphIndices_init();
  }
  // Do we have a usable GetGlyphIndices function?
  if(!fl_GetGlyphIndices) goto exit_error; // No GetGlyphIndices function, use fallback mechanism instead

  // The following code makes a best effort attempt to obtain a valid fl_gc.
  // See description in fl_width() above for an explanation.
  if (!fl_gc) { // We have no valid gc, try and obtain one
	// Use our first fltk window, or fallback to using the screen via GetDC(NULL)
	hWnd = Fl::first_window() ? fl_xid(Fl::first_window()) : NULL;
	fl_gc = GetDC(hWnd);
  }
  if (!fl_gc)goto exit_error; // no valid gc, attempt to use fallback measure

  // now convert the string to WCHAR and measure it
  len = fl_utf8toUtf16(c, n, ext_buff, wc_len);
  if(len >= wc_len) {
    if(ext_buff) {delete [] ext_buff;}
    if(gi) {delete [] gi;}
	wc_len = len + 64;
    ext_buff = new unsigned short[wc_len];
	gi = new WORD[wc_len];
    len = fl_utf8toUtf16(c, n, ext_buff, wc_len);
  }
  SelectObject(fl_gc, fl_fontsize->fid);

  if (fl_GetGlyphIndices(fl_gc, (WCHAR*)ext_buff, len, gi, 0) == GDI_ERROR) {
    // some error occured here - just return fl_measure values?
    goto exit_error;
  }

  // now we have the glyph array we measure each glyph in turn...
  for(idx = 0; idx < len; idx++){
    if (GetGlyphOutlineW (fl_gc, gi[idx], GGO_METRICS | GGO_GLYPH_INDEX,
					      &metrics, 0, NULL, &matrix) == GDI_ERROR) {
                    goto exit_error;
    }
    maxw += metrics.gmCellIncX;
	if(idx == 0) minx = metrics.gmptGlyphOrigin.x;
    dh = metrics.gmBlackBoxY - metrics.gmptGlyphOrigin.y;
	if(dh > maxh) maxh = dh;
	if(miny < metrics.gmptGlyphOrigin.y) miny = metrics.gmptGlyphOrigin.y;
  }

  // for the last cell, we only want the bounding X-extent, not the glyphs increment step
  maxw = maxw - metrics.gmCellIncX + metrics.gmBlackBoxX + metrics.gmptGlyphOrigin.x;
  w = maxw - minx;
  h = maxh + miny;
  dx = minx;
  dy = -miny;
  EXTENTS_UPDATE(dx, dy, w, h);
  return; // normal exit

exit_error:
  // some error here - just return fl_measure values
  w = (int)fl_width(c, n);
  h = fl_height();
  dx = 0;
  dy = fl_descent() - h;
  EXTENTS_UPDATE(dx, dy, w, h);
  return;
}