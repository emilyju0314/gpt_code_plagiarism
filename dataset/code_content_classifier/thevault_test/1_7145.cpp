void Fl_Text_Display::display_insert() {
  int hOffset, topLine, X, Y;
  hOffset = mHorizOffset;
  topLine = mTopLineNum;
  
  if (insert_position() < mFirstChar) {
    topLine -= count_lines(insert_position(), mFirstChar, false);
  } else if (mLineStarts[mNVisibleLines-2] != -1) {
    int lastChar = line_end(mLineStarts[mNVisibleLines-2],true);
    if (insert_position() >= lastChar)
      topLine += count_lines(lastChar - (wrap_uses_character(mLastChar) ? 0 : 1),
                             insert_position(), false);
  }
  
  /* Find the new setting for horizontal offset (this is a bit ungraceful).
   If the line is visible, just use PositionToXY to get the position
   to scroll to, otherwise, do the vertical scrolling first, then the
   horizontal */
  if (!position_to_xy( mCursorPos, &X, &Y )) {
    scroll_(topLine, hOffset);
    if (!position_to_xy( mCursorPos, &X, &Y )) {
#ifdef DEBUG
      printf ("*** display_insert/position_to_xy # GIVE UP !\n"); fflush(stdout);
#endif // DEBUG
      return;   /* Give up, it's not worth it (but why does it fail?) */
    }
  }
  if (X > text_area.x + text_area.w)
    hOffset += X-(text_area.x + text_area.w);
  else if (X < text_area.x)
    hOffset += X-text_area.x;
  
  /* Do the scroll */
  if (topLine != mTopLineNum || hOffset != mHorizOffset)
    scroll_(topLine, hOffset);
}