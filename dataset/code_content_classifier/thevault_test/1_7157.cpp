int Fl_Text_Display::get_absolute_top_line_number() const {
  if (!mContinuousWrap)
    return mTopLineNum;
  if (maintaining_absolute_top_line_number())
    return mAbsTopLineNum;
  return 0;
}