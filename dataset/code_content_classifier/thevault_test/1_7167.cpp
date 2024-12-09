int Fl_Text_Display::xy_to_position( int X, int Y, int posType ) const {
  int lineStart, lineLen, fontHeight;
  int visLineNum;
  
  /* Find the visible line number corresponding to the Y coordinate */
  fontHeight = mMaxsize;
  visLineNum = ( Y - text_area.y ) / fontHeight;
  if ( visLineNum < 0 )
    return mFirstChar;
  if ( visLineNum >= mNVisibleLines )
    visLineNum = mNVisibleLines - 1;
  
  /* Find the position at the start of the line */
  lineStart = mLineStarts[ visLineNum ];
  
  /* If the line start was empty, return the last position in the buffer */
  if ( lineStart == -1 )
    return mBuffer->length();
  
  /* Get the line text and its length */
  lineLen = vline_length( visLineNum );
  
  return handle_vline(FIND_INDEX, 
                      lineStart, lineLen, 0, 0, 
                      0, 0,
                      text_area.x, X);
}