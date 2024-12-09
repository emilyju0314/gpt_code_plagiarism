void Fl_Text_Display::measure_deleted_lines(int pos, int nDeleted) {
  IS_UTF8_ALIGNED2(buffer(), pos)

  int retPos, retLines, retLineStart, retLineEnd;
  Fl_Text_Buffer *buf = buffer();
  int nVisLines = mNVisibleLines;
  int *lineStarts = mLineStarts;
  int countFrom, lineStart;
  int visLineNum = 0, nLines = 0, i;
  /*
   ** Determine where to begin searching: either the previous newline, or
   ** if possible, limit to the start of the (original) previous displayed
   ** line, using information from the existing line starts array
   */
  if (pos >= mFirstChar && pos <= mLastChar) {
    for (i=nVisLines-1; i>0; i--)
      if (lineStarts[i] != -1 && pos >= lineStarts[i])
        break;
    if (i > 0) {
      countFrom = lineStarts[i-1];
      visLineNum = i-1;
    } else
      countFrom = buf->line_start(pos);
  } else
    countFrom = buf->line_start(pos);
  
  /*
   ** Move forward through the (new) text one line at a time, counting
   ** displayed lines, and looking for either a real newline, or for the
   ** line starts to re-sync with the original line starts array
   */
  lineStart = countFrom;
  for (;;) {
    /* advance to the next line.  If the line ended in a real newline
     or the end of the buffer, that's far enough */
    wrapped_line_counter(buf, lineStart, buf->length(), 1, true, 0,
                         &retPos, &retLines, &retLineStart, &retLineEnd);
    if (retPos >= buf->length()) {
      if (retPos != retLineEnd)
        nLines++;
      break;
    } else
      lineStart = retPos;
    nLines++;
    if (lineStart > pos + nDeleted && buf->char_at(lineStart-1) == '\n') {
      break;
    }
    
    /* Unlike in the findWrapRange() function above, we don't try to 
     resync with the line starts, because we don't know the length 
     of the inserted text yet, nor the updated style information. 
     
     Because of that, we also shouldn't resync with the line starts
     after the modification either, because we must perform the
     calculations for the deleted and inserted lines in the same way. 
     
     This can result in some unnecessary recalculation and redrawing
     overhead, and therefore we should only use this two-phase mode
     of calculation when it's really needed (continuous wrap + variable
     font width). */
  }
  mNLinesDeleted = nLines;
  mSuppressResync = 1;
}