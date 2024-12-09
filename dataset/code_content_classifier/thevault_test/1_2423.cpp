unsigned Text_Token_Stream::scan_decimal_literal_(unsigned &pos) {
  unsigned const old_pos = pos;
  char c = peek_(pos);
  if (isdigit(c) && c != '0') {
    while (isdigit(c)) {
      pos++;
      c = peek_(pos);
    }
  }
  return pos - old_pos;
}