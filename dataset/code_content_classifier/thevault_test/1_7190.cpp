void Fl::copy(const char *stuff, int len, int clipboard) {
  if (!stuff || len<0) return;

  // Convert \n -> \r\n (for old apps like Notepad, DOS)
  Lf2CrlfConvert buf(stuff, len);
  len = buf.GetLength();
  stuff = buf.GetValue();

  if (len+1 > fl_selection_buffer_length[clipboard]) {
    delete[] fl_selection_buffer[clipboard];
    fl_selection_buffer[clipboard] = new char[len+100];
    fl_selection_buffer_length[clipboard] = len+100;
  }
  memcpy(fl_selection_buffer[clipboard], stuff, len);
  fl_selection_buffer[clipboard][len] = 0; // needed for direct paste
  fl_selection_length[clipboard] = len;
  if (clipboard) {
    // set up for "delayed rendering":
    if (OpenClipboard(NULL)) {
      // if the system clipboard works, use it
      int utf16_len = fl_utf8toUtf16(fl_selection_buffer[clipboard], fl_selection_length[clipboard], 0, 0);
      EmptyClipboard();
      HGLOBAL hMem = GlobalAlloc(GHND, utf16_len * 2 + 2); // moveable and zero'ed mem alloc.
      LPVOID memLock = GlobalLock(hMem);
      fl_utf8toUtf16(fl_selection_buffer[clipboard], fl_selection_length[clipboard], (unsigned short*) memLock, utf16_len * 2);
      GlobalUnlock(hMem);
      SetClipboardData(CF_UNICODETEXT, hMem);
      CloseClipboard();
      GlobalFree(hMem);
      fl_i_own_selection[clipboard] = 0;
    } else {
      // only if it fails, instruct paste() to use the internal buffers
      fl_i_own_selection[clipboard] = 1;
    }
  }
}