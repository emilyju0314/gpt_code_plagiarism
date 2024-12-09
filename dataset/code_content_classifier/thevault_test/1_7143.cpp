int Fl_Text_Display::wrapped_column(int row, int column) const {
  int lineStart, dispLineStart;
  
  if (!mContinuousWrap || row < 0 || row > mNVisibleLines)
    return column;
  dispLineStart = mLineStarts[row];
  if (dispLineStart == -1)
    return column;
  lineStart = buffer()->line_start(dispLineStart);
  return column + buffer()->count_displayed_characters(lineStart, dispLineStart);
}