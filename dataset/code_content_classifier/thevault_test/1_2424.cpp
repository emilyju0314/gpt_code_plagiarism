unsigned Text_Token_Stream::scan_hexadecimal_literal_(unsigned &pos) {
  unsigned old_pos = pos;
  if (peek_(pos) == '0') {
    pos++;
    char c = peek_(pos);
    if (c == 'x' || c == 'X') {
      pos++;
      c = peek_(pos);
      if (!isxdigit(c)) {
        pos = old_pos;
      } else {
        while (isxdigit(c)) {
          pos++;
          c = peek_(pos);
        }
      }
    } else {
      pos = old_pos;
    }
  }
  return pos - old_pos;
}