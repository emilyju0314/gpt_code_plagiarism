int // O - font list index
Fl_Help_View::font_style(int fi, // I - font list index
                         unsigned char fs) // I - font style 0..3
{
  int ti = 0; // temp loop var

  if (fs > 3 || fi >= (int)sizeof(fref_)) return 0; // avoid crash
  for (ti = 0; ti <= 3; ti ++) // find style
    if (fi == face_[fref_[fi]][ti]) break;
  ti |= fs; // combine bits
  return face_[fref_[fi]][ti];

}