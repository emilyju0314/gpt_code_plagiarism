int Fl::compose(int& del) {
  // character composition is now handled by the OS
  del = 0;
#if defined(__APPLE__)
  // this stuff is to be treated as a function key
  if(Fl::e_length == 0 || Fl::e_keysym == FL_Enter || Fl::e_keysym == FL_KP_Enter || 
     Fl::e_keysym == FL_Tab || Fl::e_keysym == FL_Escape || Fl::e_state&(FL_META | FL_CTRL) ) {
    return 0;
  }
#else
  unsigned char ascii = (unsigned)e_text[0];
  if ((e_state & (FL_ALT | FL_META)) && !(ascii & 128)) return 0;
#endif
  if(Fl::compose_state) {
    del = 1;
    Fl::compose_state = 0;
  } else {
#ifndef __APPLE__
    // Only insert non-control characters:
    if (! (ascii & ~31 && ascii!=127)) { return 0; }
#endif
  }
  return 1;
}