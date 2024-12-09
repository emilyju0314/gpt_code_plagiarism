int Fl_Text_Display::position_to_xy( int pos, int* X, int* Y ) const {
  IS_UTF8_ALIGNED2(buffer(), pos)

  int lineStartPos, fontHeight, lineLen;
  int visLineNum;
  
  /* If position is not displayed, return false */
  if (pos < mFirstChar || (pos > mLastChar && !empty_vlines())) {
    return 0;
  }
  
  /* Calculate Y coordinate */
  if (!position_to_line(pos, &visLineNum)) {
    return 0;
  }
  if (visLineNum < 0 || visLineNum > mNBufferLines) {
    return 0;
  }
  
  fontHeight = mMaxsize;
  *Y = text_area.y + visLineNum * fontHeight;
  
  /* Get the text, length, and  buffer position of the line. If the position
   is beyond the end of the buffer and should be at the first position on
   the first empty line, don't try to get or scan the text  */
  lineStartPos = mLineStarts[visLineNum];
  if ( lineStartPos == -1 ) {
    *X = text_area.x - mHorizOffset;
    return 1;
  }
  lineLen = vline_length( visLineNum );
  *X = text_area.x + handle_vline(GET_WIDTH, lineStartPos, pos-lineStartPos, 0, 0, 0, 0, 0, 0) - mHorizOffset;
  return 1;
}