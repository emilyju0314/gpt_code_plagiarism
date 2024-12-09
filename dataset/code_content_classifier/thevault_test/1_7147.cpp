int Fl_Text_Display::move_left() {
  if ( mCursorPos <= 0 )
    return 0;
  int p = insert_position();
  int q = buffer()->prev_char_clipped(p);
  insert_position(q);
  return 1;
}