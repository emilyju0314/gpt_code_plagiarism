int Fl_Text_Display::wrap_uses_character(int lineEndPos) const {
  IS_UTF8_ALIGNED2(buffer(), lineEndPos)

  unsigned int c;
  
  if (!mContinuousWrap || lineEndPos == buffer()->length())
    return 1;
  
  c = buffer()->char_at(lineEndPos);
  return c == '\n' || ((c == '\t' || c == ' ') &&
                       lineEndPos + fl_utf8len(c) < buffer()->length());
}