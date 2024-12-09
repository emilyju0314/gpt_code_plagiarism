int Fl_Text_Display::move_up() {
  int lineStartPos, xPos, prevLineStartPos, newPos, visLineNum;
  
  /* Find the position of the start of the line.  Use the line starts array
   if possible */
  if ( position_to_line( mCursorPos, &visLineNum ) )
    lineStartPos = mLineStarts[ visLineNum ];
  else {
    lineStartPos = line_start( mCursorPos );
    visLineNum = -1;
  }
  if ( lineStartPos == 0 )
    return 0;
  
  /* Decide what column to move to, if there's a preferred column use that */
  if (mCursorPreferredXPos >= 0)
    xPos = mCursorPreferredXPos;
  else
    xPos = handle_vline(GET_WIDTH, lineStartPos, mCursorPos-lineStartPos, 
                        0, 0, 0, 0, 0, INT_MAX);
  
  /* count forward from the start of the previous line to reach the column */
  if ( visLineNum != -1 && visLineNum != 0 )
    prevLineStartPos = mLineStarts[ visLineNum - 1 ];
  else
    prevLineStartPos = rewind_lines( lineStartPos, 1 );
  
  int lineEnd = line_end(prevLineStartPos, true);
  newPos = handle_vline(FIND_INDEX_FROM_ZERO, prevLineStartPos, lineEnd-prevLineStartPos, 
                        0, 0, 0, 0, 0, xPos);
  
  /* move the cursor */
  insert_position( newPos );
  
  /* if a preferred column wasn't aleady established, establish it */
  mCursorPreferredXPos = xPos;
  return 1;
}