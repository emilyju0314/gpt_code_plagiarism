unsigned Text_Token_Stream::scan_exponent_part_(unsigned &pos) {
  unsigned const old_pos = pos;
  char c = peek_(pos);
  if (c == 'e' || c == 'E') {
    pos++;
    c = peek_(pos);
    if (c == '-' || c == '+')
      pos++;
    if (!scan_digit_sequence_(pos)) {
      pos = old_pos;
    }
  }
  return pos - old_pos;
}