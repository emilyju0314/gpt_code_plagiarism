int Fl_Text_Display::move_right() {
  if ( mCursorPos >= mBuffer->length() )
    return 0;
  int p = insert_position();
  int q = buffer()->next_char(p);
  insert_position(q);
  return 1;
}