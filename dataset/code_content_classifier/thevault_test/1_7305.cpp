int // O - font face or base font list index
Fl_Help_View::font_face(const char *sp) // I - name of font to find
{
  char buf[100], namebuf[100]; // buffers
  const char *listp, *namep; // pointers
  int ti = 0, tj = 0, tk = 0, // temp loop vars
    tnum = 0, lnum = 0, fnum = 0, // temp/last/font counters
    nfonts = 0, nfaces = 0, // numbers
    temp = 0, slen = 0, dfont = 0; // misc
  unsigned char flen[10]; // font name lengths

  slen = strlen(sp); // string length
  if (!slen) return 0; // sp not valid
  if (slen > 255) slen = 255; // set max length

  for (ti = 0, listp = sp, nfaces = 0; ti < slen; ti ++, listp ++) {
    if (ti == slen - 1 || *listp == ',') { // end or ',' char
      if (nfaces < 8 && *(listp + 1) != ',') { // skip ",,"
        flen[nfaces] = ti; // store positions
        if (ti == slen - 1) flen[nfaces] = ti + 1;
        nfaces ++; // count faces
      }
    }
  }

  for (ti = nfaces - 1; ti > 0; ti --) { // calc string lengths
    temp = flen[ti] - flen[ti - 1] - 1;
    flen[ti] = temp;
  }

  nfonts = Fl::set_fonts(0); // get ISO8859-1 fonts, ignore rest

  for (ti = 0, listp = sp; ti < nfaces; ti ++) // main loop
  {
    while (*listp == ',') listp ++; // skip ',' chars
    if (flen[ti] > sizeof(buf)-1) flen[ti] = sizeof(buf)-1; // max buffer size

	  for (tj = 0, tk = 0; tj < flen[ti]; tj ++) { // remove spaces in font names
		  if (isspace(listp[tj])) continue;
		  else if (listp[tj] == '-') break;
		  buf[tk] = tolower(listp[tj]); // copy char to lowercase
		  tk ++;
    }
    buf[tj] = '\0'; // nul-terminate
	  
    fnum = (uchar)*buf - 97; // first letter index, a = 0
    if (fnum < 0 || fnum > 25) continue; // not a..z, assume font starts with letter
    tnum = flet_[fnum]; // current face index, loop start
    for (tj = fnum + 1; tj < 27; tj ++) {
      if (flet_[tj] > 0) {
        lnum = flet_[tj]; break; // last face index, loop end
      }
    }

    slen = strlen(buf); // first word length
    for (tj = tnum; tj < lnum; tj ++) { // find current font
      fnum = face_[tj][0]; // base font index
      namep = Fl::get_font_name((Fl_Font)fnum, &temp); // fltk font name
		for (tk = 0, temp = 0; namep[tk] != '\0'; tk ++) { // remove spaces in font name
			if (isspace(namep[tk])) continue;
			else if (namep[tk] == '-') break;
			namebuf[temp] = tolower(namep[tk]); // copy chars to lowercase
			temp ++;
		}
      namebuf[tk] = '\0'; // nul-terminate
		if (!strncmp(namebuf, buf, slen)) // found name
			return fnum;
    }
	
    if (!dfont) { // check default fonts
      if (!strncmp(buf, "courier", 7)) dfont = monofont_;
      if (!strncmp(buf, "times", 5)) dfont = serifont_;
      if (!strncmp(buf, "helvetica", 9)) dfont = sansfont_;
    }
  }
	return dfont;

}