int Fl_Text_Display::position_to_line( int pos, int *lineNum ) const {
  IS_UTF8_ALIGNED2(buffer(), pos)

  int i;
  
  *lineNum = 0;
  if ( pos < mFirstChar ) return 0;
  if ( pos > mLastChar ) {
    if ( empty_vlines() ) {
      if ( mLastChar < mBuffer->length() ) {
        if ( !position_to_line( mLastChar, lineNum ) ) {
          Fl::error("Fl_Text_Display::position_to_line(): Consistency check ptvl failed");
          return 0;
        }
        return ++( *lineNum ) <= mNVisibleLines - 1;
      } else {
        position_to_line( buffer()->prev_char_clipped(mLastChar), lineNum );
        return 1;
      }
    }
    return 0;
  }
  
  for ( i = mNVisibleLines - 1; i >= 0; i-- ) {
    if ( mLineStarts[ i ] != -1 && pos >= mLineStarts[ i ] ) {
      *lineNum = i;
      return 1;
    }
  }
  return 0;   /* probably never be reached */
}