void Fl_Text_Display::xy_to_rowcol( int X, int Y, int *row,
                                   int *column, int posType ) const {
  int fontHeight = mMaxsize;
  int fontWidth = TMPFONTWIDTH;   //mFontStruct->max_bounds.width;
  
  /* Find the visible line number corresponding to the Y coordinate */
  *row = ( Y - text_area.y ) / fontHeight;
  if ( *row < 0 ) *row = 0;
  if ( *row >= mNVisibleLines ) *row = mNVisibleLines - 1;
  
  *column = ( ( X - text_area.x ) + mHorizOffset +
             ( posType == CURSOR_POS ? fontWidth / 2 : 0 ) ) / fontWidth;
  if ( *column < 0 ) * column = 0;
}