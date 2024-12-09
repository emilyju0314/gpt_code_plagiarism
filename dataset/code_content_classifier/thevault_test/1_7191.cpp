void Fl::paste(Fl_Widget &receiver, int clipboard) {
  if (!clipboard || fl_i_own_selection[clipboard]) {
    // We already have it, do it quickly without window server.
    // Notice that the text is clobbered if set_selection is
    // called in response to FL_PASTE!

    // Convert \r\n -> \n
    char *i = fl_selection_buffer[clipboard];
    if (i==0L) {
      Fl::e_text = 0; 
      return;
    }
    Fl::e_text = new char[fl_selection_length[clipboard]+1];
    char *o = Fl::e_text;
    while (*i) {
      if ( *i == '\r' && *(i+1) == '\n') i++;
      else *o++ = *i++;
    }
    *o = 0;
    Fl::e_length = o - Fl::e_text;
    receiver.handle(FL_PASTE);
    delete [] Fl::e_text;
    Fl::e_text = 0;
  } else {
    if (!OpenClipboard(NULL)) return;
    HANDLE h = GetClipboardData(CF_UNICODETEXT);
    if (h) {
      wchar_t *memLock = (wchar_t*) GlobalLock(h);
      int utf16_len = wcslen(memLock);
      Fl::e_text = (char*) malloc (utf16_len * 4 + 1);
      int utf8_len = fl_utf8fromwc(Fl::e_text, utf16_len * 4, memLock, utf16_len);
      *(Fl::e_text + utf8_len) = 0;
      LPSTR a,b;
      a = b = Fl::e_text;
      while (*a) { // strip the CRLF pairs ($%$#@^)
        if (*a == '\r' && a[1] == '\n') a++;
        else *b++ = *a++;
      }
      *b = 0;
      Fl::e_length = b - Fl::e_text;
      receiver.handle(FL_PASTE);
      GlobalUnlock(h);
      free(Fl::e_text);
      Fl::e_text = 0;
    }
    CloseClipboard();
  }
}