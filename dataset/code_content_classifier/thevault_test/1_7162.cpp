void Fl_Text_Display::draw_vline(int visLineNum, int leftClip, int rightClip,
                                 int leftCharIndex, int rightCharIndex) {
  int Y, lineStartPos, lineLen, fontHeight;
  
  //  printf("draw_vline(visLineNum=%d, leftClip=%d, rightClip=%d, leftCharIndex=%d, rightCharIndex=%d)\n",
  //         visLineNum, leftClip, rightClip, leftCharIndex, rightCharIndex);
  //  printf("nNVisibleLines=%d\n", mNVisibleLines);
  
  /* If line is not displayed, skip it */
  if ( visLineNum < 0 || visLineNum >= mNVisibleLines )
    return;
  
  /* Calculate Y coordinate of the string to draw */
  fontHeight = mMaxsize;
  Y = text_area.y + visLineNum * fontHeight;
  
  /* Get the text, length, and  buffer position of the line to display */
  lineStartPos = mLineStarts[ visLineNum ];
  if ( lineStartPos == -1 ) {
    lineLen = 0;
  } else {
    lineLen = vline_length( visLineNum );
  }
  
  /* Shrink the clipping range to the active display area */
  leftClip = max( text_area.x, leftClip );
  rightClip = min( rightClip, text_area.x + text_area.w );
  
  handle_vline(DRAW_LINE, 
               lineStartPos, lineLen, leftCharIndex, rightCharIndex,
               Y, Y+fontHeight, leftClip, rightClip);
  return;
}