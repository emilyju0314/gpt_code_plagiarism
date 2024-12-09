int Fl_Text_Display::find_x(const char *s, int len, int style, int x) const {
  IS_UTF8_ALIGNED(s)

  // TODO: use binary search which may be quicker.
  int i = 0;
  while (i<len) {
    int cl = fl_utf8len(s[i]);
    int w = int( string_width(s, i+cl, style) );
    if (w>x) 
      return i;
    i += cl;
  }  
  return len;
}