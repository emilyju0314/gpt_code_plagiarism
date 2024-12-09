double Fl_Text_Display::string_width( const char *string, int length, int style ) const {
  IS_UTF8_ALIGNED(string)

  Fl_Font font;
  Fl_Fontsize fsize;
  
  if ( mNStyles && (style & STYLE_LOOKUP_MASK) ) {
    int si = (style & STYLE_LOOKUP_MASK) - 'A';
    if (si < 0) si = 0;
    else if (si >= mNStyles) si = mNStyles - 1;
    
    font  = mStyleTable[si].font;
    fsize = mStyleTable[si].size;
  } else {
    font  = textfont();
    fsize = textsize();
  }
  fl_font( font, fsize );
  return fl_width( string, length );
}