void Fl_Text_Display::update_v_scrollbar() {
  /* The Vert. scroll bar value and slider size directly represent the top
   line number, and the number of visible lines respectively.  The scroll
   bar maximum value is chosen to generally represent the size of the whole
   buffer, with minor adjustments to keep the scroll bar widget happy */
#ifdef DEBUG
  printf("Fl_Text_Display::update_v_scrollbar():\n"
         "    mTopLineNum=%d, mNVisibleLines=%d, mNBufferLines=%d\n",
	 mTopLineNum, mNVisibleLines, mNBufferLines);
#endif // DEBUG
  
  mVScrollBar->value(mTopLineNum, mNVisibleLines, 1, mNBufferLines+2);
  mVScrollBar->linesize(3);
}