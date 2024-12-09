int Fl_Text_Display::vline_length( int visLineNum ) const {
  int nextLineStart, lineStartPos;
  
  if (visLineNum < 0 || visLineNum >= mNVisibleLines)
    return (0);
  
  lineStartPos = mLineStarts[ visLineNum ];
  
  if ( lineStartPos == -1 )
    return 0;
  
  if ( visLineNum + 1 >= mNVisibleLines )
    return mLastChar - lineStartPos;
  
  nextLineStart = mLineStarts[ visLineNum + 1 ];
  if ( nextLineStart == -1 )
    return mLastChar - lineStartPos;
  
  int nextLineStartMinus1 = buffer()->prev_char(nextLineStart);
  if (wrap_uses_character(nextLineStartMinus1))
    return nextLineStartMinus1 - lineStartPos;
  
  return nextLineStart - lineStartPos;
}