unsigned Text_Token_Stream::scan_octal_literal_(unsigned &pos) {
  unsigned old_pos = pos;
  char c = peek_(pos);
  if (c == '0') {
    while (isdigit(c) && c != '8' && c != '9') {
      pos++;
      c = peek_(pos);
    }
  }
  return pos - old_pos;
}