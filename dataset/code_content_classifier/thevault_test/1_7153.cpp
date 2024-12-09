int Fl_Text_Display::line_start(int pos) const {
  IS_UTF8_ALIGNED2(buffer(), pos)

  int retLines, retPos, retLineStart, retLineEnd;
  
  /* If we're not wrapping, use the more efficient BufStartOfLine */
  if (!mContinuousWrap)
    return buffer()->line_start(pos);
  
  wrapped_line_counter(buffer(), buffer()->line_start(pos), pos, INT_MAX, true, 0,
                       &retPos, &retLines, &retLineStart, &retLineEnd);

  IS_UTF8_ALIGNED2(buffer(), retLineStart)
  return retLineStart;
}