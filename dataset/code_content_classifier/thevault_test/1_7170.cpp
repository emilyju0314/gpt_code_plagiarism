void Fl_Text_Display::calc_line_starts( int startLine, int endLine ) {
  int startPos, bufLen = mBuffer->length();
  int line, lineEnd, nextLineStart, nVis = mNVisibleLines;
  int *lineStarts = mLineStarts;
  
  /* Clean up (possibly) messy input parameters */
  if ( endLine < 0 ) endLine = 0;
  if ( endLine >= nVis ) endLine = nVis - 1;
  if ( startLine < 0 ) startLine = 0;
  if ( startLine >= nVis ) startLine = nVis - 1;
  if ( startLine > endLine )
    return;
  
  /* Find the last known good line number -> position mapping */
  if ( startLine == 0 ) {
    lineStarts[ 0 ] = mFirstChar;
    startLine = 1;
  }
  startPos = lineStarts[ startLine - 1 ];
  
  /* If the starting position is already past the end of the text,
   fill in -1's (means no text on line) and return */
  if ( startPos == -1 ) {
    for ( line = startLine; line <= endLine; line++ )
      lineStarts[ line ] = -1;
    return;
  }
  
  /* Loop searching for ends of lines and storing the positions of the
   start of the next line in lineStarts */
  for ( line = startLine; line <= endLine; line++ ) {
    find_line_end(startPos, true, &lineEnd, &nextLineStart);
    startPos = nextLineStart;
    if ( startPos >= bufLen ) {
      /* If the buffer ends with a newline or line break, put
       buf->length() in the next line start position (instead of
       a -1 which is the normal marker for an empty line) to
       indicate that the cursor may safely be displayed there */
      if ( line == 0 || ( lineStarts[ line - 1 ] != bufLen &&
                         lineEnd != nextLineStart ) ) {
        lineStarts[ line ] = bufLen;
        line++;
      }
      break;
    }
    lineStarts[ line ] = startPos;
  }
  
  /* Set any entries beyond the end of the text to -1 */
  for ( ; line <= endLine; line++ )
    lineStarts[ line ] = -1;
}