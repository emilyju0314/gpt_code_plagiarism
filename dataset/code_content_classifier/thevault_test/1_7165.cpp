int Fl_Text_Display::position_style( int lineStartPos, int lineLen, int lineIndex) const 
{
  IS_UTF8_ALIGNED2(buffer(), lineStartPos)

  Fl_Text_Buffer * buf = mBuffer;
  Fl_Text_Buffer *styleBuf = mStyleBuffer;
  int pos, style = 0;
  
  if ( lineStartPos == -1 || buf == NULL )
    return FILL_MASK;
  
  pos = lineStartPos + min( lineIndex, lineLen );
  
  if ( lineIndex >= lineLen )
    style = FILL_MASK;
  else if ( styleBuf != NULL ) {
    style = ( unsigned char ) styleBuf->byte_at( pos );
    if (style == mUnfinishedStyle && mUnfinishedHighlightCB) {
      /* encountered "unfinished" style, trigger parsing */
      (mUnfinishedHighlightCB)( pos, mHighlightCBArg);
      style = (unsigned char) styleBuf->byte_at( pos);
    }
  }
  if (buf->primary_selection()->includes(pos))
    style |= PRIMARY_MASK;
  if (buf->highlight_selection()->includes(pos))
    style |= HIGHLIGHT_MASK;
  if (buf->secondary_selection()->includes(pos))
    style |= SECONDARY_MASK;
  return style;
}