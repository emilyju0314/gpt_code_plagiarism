int Fl_Text_Display::count_lines(int startPos, int endPos,
                                 bool startPosIsLineStart) const {
  IS_UTF8_ALIGNED2(buffer(), startPos)
  IS_UTF8_ALIGNED2(buffer(), endPos)
  
  int retLines, retPos, retLineStart, retLineEnd;
  
#ifdef DEBUG
  printf("Fl_Text_Display::count_lines(startPos=%d, endPos=%d, startPosIsLineStart=%d\n",
         startPos, endPos, startPosIsLineStart);
#endif // DEBUG
  
  /* If we're not wrapping use simple (and more efficient) BufCountLines */
  if (!mContinuousWrap)
    return buffer()->count_lines(startPos, endPos);
  
  wrapped_line_counter(buffer(), startPos, endPos, INT_MAX,
                       startPosIsLineStart, 0, &retPos, &retLines, &retLineStart,
                       &retLineEnd);
  
#ifdef DEBUG
  printf("   # after WLC: retPos=%d, retLines=%d, retLineStart=%d, retLineEnd=%d\n",
         retPos, retLines, retLineStart, retLineEnd);
#endif // DEBUG
  
  return retLines;
}