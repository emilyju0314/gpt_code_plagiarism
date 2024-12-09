int Fl_Text_Display::rewind_lines(int startPos, int nLines) {
  IS_UTF8_ALIGNED2(buffer(), startPos)

  Fl_Text_Buffer *buf = buffer();
  int pos, lineStart, retLines, retPos, retLineStart, retLineEnd;
  
  /* If we're not wrapping, use the more efficient BufCountBackwardNLines */
  if (!mContinuousWrap)
    return buf->rewind_lines(startPos, nLines);
  
  pos = startPos;
  for (;;) {
    lineStart = buf->line_start(pos);
    wrapped_line_counter(buf, lineStart, pos, INT_MAX, true, 0, 
                         &retPos, &retLines, &retLineStart, &retLineEnd, false);
    if (retLines > nLines)
      return skip_lines(lineStart, retLines-nLines, true);
    nLines -= retLines;
    pos = lineStart - 1;
    if (pos < 0)
      return 0;
    nLines -= 1;
  }
}