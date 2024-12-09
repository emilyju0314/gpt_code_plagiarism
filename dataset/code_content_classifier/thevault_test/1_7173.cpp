int Fl_Text_Display::scroll_(int topLineNum, int horizOffset) {
  /* Limit the requested scroll position to allowable values */
  if (topLineNum > mNBufferLines + 3 - mNVisibleLines)
    topLineNum = mNBufferLines + 3 - mNVisibleLines;
  if (topLineNum < 1) topLineNum = 1;
  
  if (horizOffset > longest_vline() - text_area.w)
    horizOffset = longest_vline() - text_area.w;
  if (horizOffset < 0) horizOffset = 0;
  
  /* Do nothing if scroll position hasn't actually changed or there's no
   window to draw in yet */
  if (mHorizOffset == horizOffset && mTopLineNum == topLineNum)
    return 0;
  
  /* If the vertical scroll position has changed, update the line
   starts array and related counters in the text display */
  offset_line_starts(topLineNum);
  
  /* Just setting mHorizOffset is enough information for redisplay */
  mHorizOffset = horizOffset;
  
  // redraw all text
  damage(FL_DAMAGE_EXPOSE);
  return 1;
}