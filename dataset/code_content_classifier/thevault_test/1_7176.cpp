int Fl_Text_Display::measure_vline( int visLineNum ) const {
  int lineLen = vline_length( visLineNum );
  int lineStartPos = mLineStarts[ visLineNum ];
  if (lineStartPos < 0 || lineLen == 0) return 0;
  return handle_vline(GET_WIDTH, lineStartPos, lineLen, 0, 0, 0, 0, 0, 0);
}