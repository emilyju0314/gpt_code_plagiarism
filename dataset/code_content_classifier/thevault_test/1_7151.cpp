int Fl_Text_Display::skip_lines(int startPos, int nLines,
                                bool startPosIsLineStart) {
  IS_UTF8_ALIGNED2(buffer(), startPos)

  int retLines, retPos, retLineStart, retLineEnd;
  
  /* if we're not wrapping use more efficient BufCountForwardNLines */
  if (!mContinuousWrap)
    return buffer()->skip_lines(startPos, nLines);
  
  /* wrappedLineCounter can't handle the 0 lines case */
  if (nLines == 0)
    return startPos;
  
  /* use the common line counting routine to count forward */
  wrapped_line_counter(buffer(), startPos, buffer()->length(),
                       nLines, startPosIsLineStart, 0, 
                       &retPos, &retLines, &retLineStart, &retLineEnd);
  IS_UTF8_ALIGNED2(buffer(), retPos)
  return retPos;
}