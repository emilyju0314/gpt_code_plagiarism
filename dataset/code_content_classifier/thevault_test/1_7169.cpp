void Fl_Text_Display::offset_line_starts( int newTopLineNum ) {
  int oldTopLineNum = mTopLineNum;
  int oldFirstChar = mFirstChar;
  int lineDelta = newTopLineNum - oldTopLineNum;
  int nVisLines = mNVisibleLines;
  int *lineStarts = mLineStarts;
  int i, lastLineNum;
  Fl_Text_Buffer *buf = mBuffer;
  
  /* If there was no offset, nothing needs to be changed */
  if ( lineDelta == 0 )
    return;
  
  /* Find the new value for mFirstChar by counting lines from the nearest
   known line start (start or end of buffer, or the closest value in the
   lineStarts array) */
  lastLineNum = oldTopLineNum + nVisLines - 1;
  if ( newTopLineNum < oldTopLineNum && newTopLineNum < -lineDelta ) {
    mFirstChar = skip_lines( 0, newTopLineNum - 1, true );
  } else if ( newTopLineNum < oldTopLineNum ) {
    mFirstChar = rewind_lines( mFirstChar, -lineDelta );
  } else if ( newTopLineNum < lastLineNum ) {
    mFirstChar = lineStarts[ newTopLineNum - oldTopLineNum ];
  } else if ( newTopLineNum - lastLineNum < mNBufferLines - newTopLineNum ) {
    mFirstChar = skip_lines( lineStarts[ nVisLines - 1 ],
                            newTopLineNum - lastLineNum, true );
  } else {
    mFirstChar = rewind_lines( buf->length(), mNBufferLines - newTopLineNum + 1 );
  }
  
  /* Fill in the line starts array */
  if ( lineDelta < 0 && -lineDelta < nVisLines ) {
    for ( i = nVisLines - 1; i >= -lineDelta; i-- )
      lineStarts[ i ] = lineStarts[ i + lineDelta ];
    calc_line_starts( 0, -lineDelta );
  } else if ( lineDelta > 0 && lineDelta < nVisLines ) {
    for ( i = 0; i < nVisLines - lineDelta; i++ )
      lineStarts[ i ] = lineStarts[ i + lineDelta ];
    calc_line_starts( nVisLines - lineDelta, nVisLines - 1 );
  } else
    calc_line_starts( 0, nVisLines );
  
  /* Set lastChar and mTopLineNum */
  calc_last_char();
  mTopLineNum = newTopLineNum;
  
  /* If we're numbering lines or being asked to maintain an absolute line
   number, re-calculate the absolute line number */
  absolute_top_line_number(oldFirstChar);
}