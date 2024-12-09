void Fl_Text_Display::overstrike(const char* text) {
  IS_UTF8_ALIGNED2(buffer(), mCursorPos)
  IS_UTF8_ALIGNED(text)
  
  int startPos = mCursorPos;
  Fl_Text_Buffer *buf = mBuffer;
  int lineStart = buf->line_start( startPos );
  int textLen = strlen( text );
  int i, p, endPos, indent, startIndent, endIndent;
  const char *c;
  unsigned int ch;
  char *paddedText = NULL;
  
  /* determine how many displayed character positions are covered */
  startIndent = mBuffer->count_displayed_characters( lineStart, startPos );
  indent = startIndent;
  for ( c = text; *c != '\0'; c += fl_utf8len(*c) )
    indent++;
  endIndent = indent;
  
  /* find which characters to remove, and if necessary generate additional
   padding to make up for removed control characters at the end */
  indent = startIndent;
  for ( p = startPos; ; p=buffer()->next_char(p) ) {
    if ( p == buf->length() )
      break;
    ch = buf->char_at( p );
    if ( ch == '\n' )
      break;
    indent++;
    if ( indent == endIndent ) {
      p++;
      break;
    } else if ( indent > endIndent ) {
      if ( ch != '\t' ) {
        p++;
        paddedText = new char [ textLen + FL_TEXT_MAX_EXP_CHAR_LEN + 1 ];
        strcpy( paddedText, text );
        for ( i = 0; i < indent - endIndent; i++ )
          paddedText[ textLen + i ] = ' ';
        paddedText[ textLen + i ] = '\0';
      }
      break;
    }
  }
  endPos = p;
  
  mCursorToHint = startPos + textLen;
  buf->replace( startPos, endPos, paddedText == NULL ? text : paddedText );
  mCursorToHint = NO_HINT;
  if ( paddedText != NULL )
    delete [] paddedText;
}