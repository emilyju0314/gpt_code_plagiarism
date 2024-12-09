void Fl_Text_Display::draw_text( int left, int top, int width, int height ) {
  int fontHeight, firstLine, lastLine, line;
  
  /* find the line number range of the display */
  fontHeight = mMaxsize ? mMaxsize : textsize_;
  firstLine = ( top - text_area.y - fontHeight + 1 ) / fontHeight;
  lastLine = ( top + height - text_area.y ) / fontHeight + 1;
  
  fl_push_clip( left, top, width, height );
  
  /* draw the lines */
  for ( line = firstLine; line <= lastLine; line++ )
    draw_vline( line, left, left + width, 0, INT_MAX );
  
  /* draw the line numbers if exposed area includes them */
  if (mLineNumWidth != 0 && left <= mLineNumLeft + mLineNumWidth)
    draw_line_numbers(false);
  
  fl_pop_clip();
}