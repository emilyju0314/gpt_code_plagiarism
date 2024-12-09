void Fl_Text_Display::draw_range(int startpos, int endpos) {
  startpos = buffer()->utf8_align(startpos);
  endpos = buffer()->utf8_align(endpos);
  
  int i, startLine, lastLine, startIndex, endIndex;
  
  /* If the range is outside of the displayed text, just return */
  if ( endpos < mFirstChar || ( startpos > mLastChar && !empty_vlines() ) ) 
    return;
  
  /* Clean up the starting and ending values */
  if ( startpos < 0 ) startpos = 0;
  if ( startpos > mBuffer->length() ) startpos = mBuffer->length();
  if ( endpos < 0 ) endpos = 0;
  if ( endpos > mBuffer->length() ) endpos = mBuffer->length();
  
  /* Get the starting and ending lines */
  if ( startpos < mFirstChar )
    startpos = mFirstChar;
  if ( !position_to_line( startpos, &startLine ) )
    startLine = mNVisibleLines - 1;
  if ( endpos >= mLastChar ) {
    lastLine = mNVisibleLines - 1;
  } else {
    if ( !position_to_line( endpos, &lastLine ) ) {
      /* shouldn't happen */
      lastLine = mNVisibleLines - 1;
    }
  }
  
  /* Get the starting and ending positions within the lines */
  startIndex = mLineStarts[ startLine ] == -1 ? 0 : startpos - mLineStarts[ startLine ];
  if ( endpos >= mLastChar )
    endIndex = INT_MAX;
  else if ( mLineStarts[ lastLine ] == -1 )
    endIndex = 0;
  else
    endIndex = endpos - mLineStarts[ lastLine ];
  
  /* If the starting and ending lines are the same, redisplay the single
   line between "start" and "end" */
  if ( startLine == lastLine ) {
    draw_vline( startLine, 0, INT_MAX, startIndex, endIndex );
    return;
  }
  
  /* Redisplay the first line from "start" */
  draw_vline( startLine, 0, INT_MAX, startIndex, INT_MAX );
  
  /* Redisplay the lines in between at their full width */
  for ( i = startLine + 1; i < lastLine; i++ )
    draw_vline( i, 0, INT_MAX, 0, INT_MAX );
  
  /* Redisplay the last line to "end" */
  draw_vline( lastLine, 0, INT_MAX, 0, endIndex );
}