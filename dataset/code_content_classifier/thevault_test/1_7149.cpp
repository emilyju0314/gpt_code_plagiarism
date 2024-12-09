int Fl_Text_Display::move_down() {
  int lineStartPos, xPos, newPos, visLineNum;
  
  if ( mCursorPos == mBuffer->length() )
    return 0;
  
  if ( position_to_line( mCursorPos, &visLineNum ) )
    lineStartPos = mLineStarts[ visLineNum ];
  else {
    lineStartPos = line_start( mCursorPos );
    visLineNum = -1;
  }
  if (mCursorPreferredXPos >= 0) {
    xPos = mCursorPreferredXPos;
  } else {
    xPos = handle_vline(GET_WIDTH, lineStartPos, mCursorPos-lineStartPos, 
                        0, 0, 0, 0, 0, INT_MAX);
  }
  
  int nextLineStartPos = skip_lines( lineStartPos, 1, true );
  int lineEnd = line_end(nextLineStartPos, true);
  newPos = handle_vline(FIND_INDEX_FROM_ZERO, nextLineStartPos, lineEnd-nextLineStartPos, 
                        0, 0, 0, 0, 0, xPos);
  
  insert_position( newPos );
  mCursorPreferredXPos = xPos;
  return 1;
}