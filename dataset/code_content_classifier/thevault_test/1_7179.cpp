void Fl_Text_Display::wrapped_line_counter(Fl_Text_Buffer *buf, int startPos,
                                           int maxPos, int maxLines, bool startPosIsLineStart, int styleBufOffset,
                                           int *retPos, int *retLines, int *retLineStart, int *retLineEnd,
                                           bool countLastLineMissingNewLine) const {
  IS_UTF8_ALIGNED2(buf, startPos)
  IS_UTF8_ALIGNED2(buf, maxPos)

  int lineStart, newLineStart = 0, b, p, colNum, wrapMarginPix;
  int i, foundBreak;
  double width;
  int nLines = 0;
  unsigned int c;
  
  /* Set the warp margin to the warp column or the view width */
  if (mWrapMarginPix != 0) {
    wrapMarginPix = mWrapMarginPix;
  } else {
    wrapMarginPix = text_area.w;
  }
  
  /* Find the start of the line if the start pos is not marked as a
   line start. */
  if (startPosIsLineStart)
    lineStart = startPos;
  else
    lineStart = line_start(startPos);
  
  /*
   ** Loop until position exceeds maxPos or line count exceeds maxLines.
   ** (actually, continues beyond maxPos to end of line containing maxPos,
   ** in case later characters cause a word wrap back before maxPos)
   */
  colNum = 0;
  width = 0;
  for (p=lineStart; p<buf->length(); p=buf->next_char(p)) {
    c = buf->char_at(p);  // UCS-4
    
    /* If the character was a newline, count the line and start over,
     otherwise, add it to the width and column counts */
    if (c == '\n') {
      if (p >= maxPos) {
        *retPos = maxPos;
        *retLines = nLines;
        *retLineStart = lineStart;
        *retLineEnd = maxPos;
        return;
      }
      nLines++;
      int p1 = buf->next_char(p);
      if (nLines >= maxLines) {
        *retPos = p1;
        *retLines = nLines;
        *retLineStart = p1;
        *retLineEnd = p;
        return;
      }
      lineStart = p1;
      colNum = 0;
      width = 0;
    } else {
      const char *s = buf->address(p);
      colNum++;
      // FIXME: it is not a good idea to simply add character widths because on
      // some platforms, the width is a floating point value and depends on the 
      // previous character as well.
      width += measure_proportional_character(s, width, p+styleBufOffset);
    }
    
    /* If character exceeded wrap margin, find the break point and wrap there */
    if (width > wrapMarginPix) {
      foundBreak = false;
      for (b=p; b>=lineStart; b=buf->prev_char(b)) {
        c = buf->char_at(b);
        if (c == '\t' || c == ' ') {
          newLineStart = buf->next_char(b);
          colNum = 0;
          width = 0;
          int iMax = buf->next_char(p);
          for (i=buf->next_char(b); i<iMax; i = buf->next_char(i)) {
            width += measure_proportional_character(buf->address(i), width, 
                                                    i+styleBufOffset);
            colNum++;
          }
          foundBreak = true;
          break;
        }
      }
      if (!foundBreak) { /* no whitespace, just break at margin */
        newLineStart = max(p, buf->next_char(lineStart));
        const char *s = buf->address(b);
        colNum++;
        width = measure_proportional_character(s, 0, p+styleBufOffset);
      }
      if (p >= maxPos) {
        *retPos = maxPos;
        *retLines = maxPos < newLineStart ? nLines : nLines + 1;
        *retLineStart = maxPos < newLineStart ? lineStart : newLineStart;
        *retLineEnd = maxPos;
        return;
      }
      nLines++;
      if (nLines >= maxLines) {
        *retPos = foundBreak ? buf->next_char(b) : max(p, buf->next_char(lineStart));
        *retLines = nLines;
        *retLineStart = lineStart;
        *retLineEnd = foundBreak ? b : p;
        return;
      }
      lineStart = newLineStart;
    }
  }
  
  /* reached end of buffer before reaching pos or line target */
  *retPos = buf->length();
  *retLines = nLines;
  if (countLastLineMissingNewLine && colNum > 0) 
    *retLines = buf->next_char(*retLines);
  *retLineStart = lineStart;
  *retLineEnd = buf->length();
}