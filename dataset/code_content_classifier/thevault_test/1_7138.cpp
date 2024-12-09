void Fl_Text_Display::insert(const char* text) {
  IS_UTF8_ALIGNED2(buffer(), mCursorPos)
  IS_UTF8_ALIGNED(text)
  
  int pos = mCursorPos;
  
  mCursorToHint = pos + strlen( text );
  mBuffer->insert( pos, text );
  mCursorToHint = NO_HINT;
}