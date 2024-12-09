void Fl_Text_Display::draw_line_numbers(bool /*clearAll*/) {
#if 0
  int y, line, visLine, nCols, lineStart;
  char lineNumString[12];
  int lineHeight = mMaxsize ? mMaxsize : textsize_;
  int charWidth = TMPFONTWIDTH;   //mFontStruct->max_bounds.width;
  
  /* Don't draw if mLineNumWidth == 0 (line numbers are hidden), or widget is
   not yet realized */
  if (mLineNumWidth == 0 || visible_r())
    return;
  
  /* GC is allocated on demand, since not everyone will use line numbering */
  if (textD->lineNumGC == NULL) {
    XGCValues values;
    values.foreground = textD->lineNumFGPixel;
    values.background = textD->bgPixel;
    values.font = textD->fontStruct->fid;
    textD->lineNumGC = XtGetGC(textD->w,
                               GCFont| GCForeground | GCBackground, &values);
  }
  
  /* Erase the previous contents of the line number area, if requested */
  if (clearAll)
    XClearArea(XtDisplay(textD->w), XtWindow(textD->w), textD->lineNumLeft,
               textD->top, textD->lineNumWidth, textD->height, False);
  
  /* Draw the line numbers, aligned to the text */
  nCols = min(11, textD->lineNumWidth / charWidth);
  y = textD->top;
  line = getAbsTopLineNum(textD);
  for (visLine=0; visLine < textD->nVisibleLines; visLine++) {
    lineStart = textD->lineStarts[visLine];
    if (lineStart != -1 && (lineStart==0 ||
                            BufGetCharacter(textD->buffer, lineStart-1)=='\n')) {
      sprintf(lineNumString, "%*d", nCols, line);
      XDrawImageString(XtDisplay(textD->w), XtWindow(textD->w),
                       textD->lineNumGC, textD->lineNumLeft, y + textD->ascent,
                       lineNumString, strlen(lineNumString));
      line++;
    } else {
      XClearArea(XtDisplay(textD->w), XtWindow(textD->w),
                 textD->lineNumLeft, y, textD->lineNumWidth,
                 textD->ascent + textD->descent, False);
      if (visLine == 0)
        line++;
    }
    y += lineHeight;
  }
#endif
}