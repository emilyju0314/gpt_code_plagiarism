Fl_Text_Display::Fl_Text_Display(int X, int Y, int W, int H, const char* l)
: Fl_Group(X, Y, W, H, l) {
  int i;
  
  mMaxsize = 0;
  damage_range1_start = damage_range1_end = -1;
  damage_range2_start = damage_range2_end = -1;
  dragPos = dragging = 0;
  dragType = DRAG_NONE;
  display_insert_position_hint = 0;
  shortcut_ = 0;
  
  color(FL_BACKGROUND2_COLOR, FL_SELECTION_COLOR);
  box(FL_DOWN_FRAME);
  textsize(FL_NORMAL_SIZE);
  textcolor(FL_FOREGROUND_COLOR);
  textfont(FL_HELVETICA);
  set_flag(SHORTCUT_LABEL);
  
  text_area.x = 0;
  text_area.y = 0;
  text_area.w = 0;
  text_area.h = 0;
  
  mVScrollBar = new Fl_Scrollbar(0,0,1,1);
  mVScrollBar->callback((Fl_Callback*)v_scrollbar_cb, this);
  mHScrollBar = new Fl_Scrollbar(0,0,1,1);
  mHScrollBar->callback((Fl_Callback*)h_scrollbar_cb, this);
  mHScrollBar->type(FL_HORIZONTAL);
  
  end();
  
  scrollbar_width(Fl::scrollbar_size());
  scrollbar_align(FL_ALIGN_BOTTOM_RIGHT);
  
  mCursorOn = 0;
  mCursorPos = 0;
  mCursorOldY = -100;
  mCursorToHint = NO_HINT;
  mCursorStyle = NORMAL_CURSOR;
  mCursorPreferredXPos = -1;
  mBuffer = 0;
  mFirstChar = 0;
  mLastChar = 0;
  mNBufferLines = 0;
  mTopLineNum = mTopLineNumHint = 1;
  mAbsTopLineNum = 1;
  mNeedAbsTopLineNum = 0;
  mHorizOffset = mHorizOffsetHint = 0;
  
  mCursor_color = FL_FOREGROUND_COLOR;
  
  mStyleBuffer = 0;
  mStyleTable = 0;
  mNStyles = 0;
  mNVisibleLines = 1;
  mLineStarts = new int[mNVisibleLines];
  mLineStarts[0] = 0;
  for (i=1; i<mNVisibleLines; i++)
    mLineStarts[i] = -1;
  mSuppressResync = 0;
  mNLinesDeleted = 0;
  mModifyingTabDistance = 0;
  
  mUnfinishedStyle = 0;
  mUnfinishedHighlightCB = 0;
  mHighlightCBArg = 0;
  
  mLineNumLeft = mLineNumWidth = 0;
  mContinuousWrap = 0;
  mWrapMarginPix = 0;
  mSuppressResync = mNLinesDeleted = mModifyingTabDistance = 0;
}