int Fl_Text_Display::line_end(int pos, bool startPosIsLineStart) const {
  IS_UTF8_ALIGNED2(buffer(), pos)

  int retLines, retPos, retLineStart, retLineEnd;
  
  /* If we're not wrapping use more efficien BufEndOfLine */
  if (!mContinuousWrap)
    return buffer()->line_end(pos);
  
  if (pos == buffer()->length())
    return pos;
  
  wrapped_line_counter(buffer(), pos, buffer()->length(), 1,
                       startPosIsLineStart, 0, &retPos, &retLines, &retLineStart,
                       &retLineEnd);
  
  IS_UTF8_ALIGNED2(buffer(), retLineEnd)
  return retLineEnd;
}