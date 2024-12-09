unsigned Text_Token_Stream::scan_digit_sequence_(unsigned &pos) {
  unsigned const old_pos = pos;
  while (isdigit(peek_(pos)))
    pos++;
  return pos - old_pos;
}