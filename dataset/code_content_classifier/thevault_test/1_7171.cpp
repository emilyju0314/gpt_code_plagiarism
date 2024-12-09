void Fl_Text_Display::calc_last_char() {
  int i;
  for (i = mNVisibleLines - 1; i >= 0 && mLineStarts[i] == -1; i--) ;
  mLastChar = i < 0 ? 0 : line_end(mLineStarts[i], true);
}