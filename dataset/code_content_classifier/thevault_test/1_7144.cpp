int Fl_Text_Display::wrapped_row(int row) const{
  if (!mContinuousWrap || row < 0 || row > mNVisibleLines)
    return row;
  return buffer()->count_lines(mFirstChar, mLineStarts[row]);
}