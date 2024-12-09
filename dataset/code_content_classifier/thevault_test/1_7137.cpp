void Fl_Text_Display::wrap_mode(int wrap, int wrapMargin) {
  switch (wrap) {
    case WRAP_NONE: 
      mWrapMarginPix = 0;
      mContinuousWrap = 0;
      break;
    case WRAP_AT_COLUMN: 
    default:
      mWrapMarginPix = int(col_to_x(wrapMargin));
      mContinuousWrap = 1;
      break;
    case WRAP_AT_PIXEL: 
      mWrapMarginPix = wrapMargin;
      mContinuousWrap = 1;
      break;
    case WRAP_AT_BOUNDS: 
      mWrapMarginPix = 0;
      mContinuousWrap = 1;
      break;
  }
  
  if (buffer()) {
    /* wrapping can change the total number of lines, re-count */
    mNBufferLines = count_lines(0, buffer()->length(), true);
    
    /* changing wrap margins or changing from wrapped mode to non-wrapped
     can leave the character at the top no longer at a line start, and/or
     change the line number */
    mFirstChar = line_start(mFirstChar);
    mTopLineNum = count_lines(0, mFirstChar, true) + 1;
    
    reset_absolute_top_line_number();
    
    /* update the line starts array */
    calc_line_starts(0, mNVisibleLines);
    calc_last_char();
  } else {
    // No buffer, so just clear the state info for later...
    mNBufferLines  = 0;
    mFirstChar     = 0;
    mTopLineNum    = 1;
    mAbsTopLineNum = 0;
  }
  
  resize(x(), y(), w(), h());
}