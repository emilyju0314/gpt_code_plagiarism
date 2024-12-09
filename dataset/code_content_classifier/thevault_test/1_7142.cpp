int Fl_Text_Display::in_selection( int X, int Y ) const {
  int pos = xy_to_position( X, Y, CHARACTER_POS );
  IS_UTF8_ALIGNED2(buffer(), pos)
  Fl_Text_Buffer *buf = mBuffer;
  return buf->primary_selection()->includes(pos);
}