int Fl_Text_Display::longest_vline() const {
  int longest = 0;
  for (int i = 0; i < mNVisibleLines; i++)
    longest = max(longest, measure_vline(i));
  return longest;
}