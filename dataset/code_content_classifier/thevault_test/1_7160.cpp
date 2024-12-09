int Fl_Text_Display::handle_vline(
                                  int mode, 
                                  int lineStartPos, int lineLen, int leftChar, int rightChar,
                                  int Y, int bottomClip,
                                  int leftClip, int rightClip) const
{
  IS_UTF8_ALIGNED2(buffer(), lineStartPos)

  // FIXME: we need to allow two modes for FIND_INDEX: one on the edge of the 
  // FIXME: character for selection, and one on the character center for cursors.
  int i, X, startX, startIndex, style, charStyle;
  char *lineStr;
  
  if ( lineStartPos == -1 ) {
    lineStr = NULL;
  } else {
    lineStr = mBuffer->text_range( lineStartPos, lineStartPos + lineLen );
  }
  
  if (mode==GET_WIDTH) {
    X = 0;
  } else if (mode==FIND_INDEX_FROM_ZERO) {
    X = 0; 
    mode = FIND_INDEX;
  } else {
    X = text_area.x - mHorizOffset;
  }
  
  startX = X;
  startIndex = 0;
  if (!lineStr) {
    // just clear the background
    if (mode==DRAW_LINE) {
      style = position_style(lineStartPos, lineLen, -1);
      draw_string( style|BG_ONLY_MASK, text_area.x, Y, text_area.x+text_area.w, lineStr, lineLen );
    }
    if (mode==FIND_INDEX) {
      IS_UTF8_ALIGNED2(buffer(), lineStartPos)
      return lineStartPos;
    }
    return 0;
  }
  
  char currChar = 0, prevChar = 0;
  // draw the line
  style = position_style(lineStartPos, lineLen, 0);
  for (i=0; i<lineLen; ) {
    currChar = lineStr[i]; // one byte is enough to handele tabs and other cases
    int len = fl_utf8len(currChar);
    if (len<=0) len = 1; // OUCH!
    charStyle = position_style(lineStartPos, lineLen, i);
    if (charStyle!=style || currChar=='\t' || prevChar=='\t') {
      // draw a segment whenever the style changes or a Tab is found
      int w = 0;
      if (prevChar=='\t') {
        // draw a single Tab space
        int tab = col_to_x(4);
        int xAbs = (mode==GET_WIDTH) ? startX : startX+mHorizOffset-text_area.x;
        w = (((xAbs/tab)+1)*tab) - xAbs;
        if (mode==DRAW_LINE)
          draw_string( style|BG_ONLY_MASK, startX, Y, startX+w, 0, 0 );
        if (mode==FIND_INDEX && startX+w>rightClip) {
          // find x pos inside block
          free(lineStr);
          return lineStartPos + startIndex;
        }
      } else {
        // draw a text segment
        w = int( string_width( lineStr+startIndex, i-startIndex, style ) );
        if (mode==DRAW_LINE)
          draw_string( style, startX, Y, startX+w, lineStr+startIndex, i-startIndex );
        if (mode==FIND_INDEX && startX+w>rightClip) {
          // find x pos inside block
          int di = find_x(lineStr+startIndex, i-startIndex, style, rightClip-startX);
          free(lineStr);
          IS_UTF8_ALIGNED2(buffer(), (lineStartPos+startIndex+di))
          return lineStartPos + startIndex + di;
        }
      }
      style = charStyle;
      startX += w;
      startIndex = i;
    }
    i += len;
    prevChar = currChar;
  }
  int w = 0;
  if (currChar=='\t') {
    // draw a single Tab space
    int tab = col_to_x(4);
    int xAbs = (mode==GET_WIDTH) ? startX : startX+mHorizOffset-text_area.x;
    w = (((xAbs/tab)+1)*tab) - xAbs;
    if (mode==DRAW_LINE)
      draw_string( style|BG_ONLY_MASK, startX, Y, startX+w, 0, 0 );
    if (mode==FIND_INDEX) {
      // find x pos inside block
      free(lineStr);
      return lineStartPos + startIndex + ( rightClip-startX>w ? 1 : 0 );
    }
  } else {
    w = int( string_width( lineStr+startIndex, i-startIndex, style ) );
    if (mode==DRAW_LINE)
      draw_string( style, startX, Y, startX+w, lineStr+startIndex, i-startIndex );
    if (mode==FIND_INDEX) {
      // find x pos inside block
      int di = find_x(lineStr+startIndex, i-startIndex, style, rightClip-startX);
      free(lineStr);
      IS_UTF8_ALIGNED2(buffer(), (lineStartPos+startIndex+di))
      return lineStartPos + startIndex + di;
    }
  }
  if (mode==GET_WIDTH) {
    free(lineStr);
    return startX+w;
  }
  
  // clear the rest of the line
  startX += w;
  style = position_style(lineStartPos, lineLen, i);
  if (mode==DRAW_LINE)
    draw_string( style|BG_ONLY_MASK, startX, Y, text_area.x+text_area.w, lineStr, lineLen );
  
  free(lineStr);
  IS_UTF8_ALIGNED2(buffer(), (lineStartPos+lineLen))
  return lineStartPos + lineLen;
}