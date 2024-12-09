void Fl_Text_Display::insert_position( int newPos ) {
  IS_UTF8_ALIGNED2(buffer(), newPos)
  
  /* make sure new position is ok, do nothing if it hasn't changed */
  if ( newPos == mCursorPos ) return;
  if ( newPos < 0 ) newPos = 0;
  if ( newPos > mBuffer->length() ) newPos = mBuffer->length();
  
  /* cursor movement cancels vertical cursor motion column */
  mCursorPreferredXPos = -1;
  
  /* erase the cursor at it's previous position */
  redisplay_range(buffer()->prev_char_clipped(mCursorPos), buffer()->next_char(mCursorPos));
  
  mCursorPos = newPos;
  
  /* draw cursor at its new position */
  redisplay_range(buffer()->prev_char_clipped(mCursorPos), buffer()->next_char(mCursorPos));
}