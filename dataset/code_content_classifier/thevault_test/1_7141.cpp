int Fl_Text_Display::position_to_linecol( int pos, int* lineNum, int* column ) const {
  IS_UTF8_ALIGNED2(buffer(), pos)
  
  int retVal;
  
  /* In continuous wrap mode, the absolute (non-wrapped) line count is
   maintained separately, as needed.  Only return it if we're actually
   keeping track of it and pos is in the displayed text */
  if (mContinuousWrap) {
    if (!maintaining_absolute_top_line_number() || pos < mFirstChar || pos > mLastChar)
      return 0;
    *lineNum = mAbsTopLineNum + buffer()->count_lines(mFirstChar, pos);
    *column = buffer()->count_displayed_characters(buffer()->line_start(pos), pos);
    return 1;
  }
  
  retVal = position_to_line( pos, lineNum );
  if ( retVal ) {
    *column = mBuffer->count_displayed_characters( mLineStarts[ *lineNum ], pos );
    *lineNum += mTopLineNum;
  }
  return retVal;
}