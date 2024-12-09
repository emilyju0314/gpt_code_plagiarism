void Fl_Text_Display::find_line_end(int startPos, bool startPosIsLineStart,
                                    int *lineEnd, int *nextLineStart) const {
  IS_UTF8_ALIGNED2(buffer(), startPos)

  int retLines, retLineStart;
  
  /* if we're not wrapping use more efficient BufEndOfLine */
  if (!mContinuousWrap) {
    int le = buffer()->line_end(startPos);
    int ls = buffer()->next_char(le);
    *lineEnd = le;
    *nextLineStart = min(buffer()->length(), ls);
    return;
  }
  
  /* use the wrapped line counter routine to count forward one line */
  wrapped_line_counter(buffer(), startPos, buffer()->length(),
                       1, startPosIsLineStart, 0, nextLineStart, &retLines,
                       &retLineStart, lineEnd);
}