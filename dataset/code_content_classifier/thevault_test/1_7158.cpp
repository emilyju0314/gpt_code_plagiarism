void Fl_Text_Display::absolute_top_line_number(int oldFirstChar) {
  if (maintaining_absolute_top_line_number()) {
    if (mFirstChar < oldFirstChar)
      mAbsTopLineNum -= buffer()->count_lines(mFirstChar, oldFirstChar);
    else
      mAbsTopLineNum += buffer()->count_lines(oldFirstChar, mFirstChar);
  }
}