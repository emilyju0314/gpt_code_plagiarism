double Fl_Text_Display::measure_proportional_character(const char *s, int xPix, int pos) const {
  IS_UTF8_ALIGNED(s)
  
  if (*s=='\t') {
    int tab = col_to_x(4);
    return (((xPix/tab)+1)*tab) - xPix;
  }
  
  int charLen = fl_utf8len(*s), style = 0;
  if (mStyleBuffer) {
    style = mStyleBuffer->byte_at(pos);
  }
  return string_width(s, charLen, style);
}