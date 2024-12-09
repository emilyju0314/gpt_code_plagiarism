unsigned Text_Token_Stream::scan_fractional_constant_(unsigned &pos) {
  unsigned const old_pos = pos;
  if (scan_digit_sequence_(pos) > 0) {
    if (peek_(pos) != '.') {
      pos = old_pos;
    } else {
      pos++;
      scan_digit_sequence_(pos);
    }
  } else if (peek_(pos) == '.') {
    pos++;
    if (scan_digit_sequence_(pos) == 0) {
      pos = old_pos;
    }
  }
  return pos - old_pos;
}