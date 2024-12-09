unsigned Text_Token_Stream::scan_integer_literal_() {
  unsigned pos = 0;
  if (scan_decimal_literal_(pos) > 0) {
  } else if (scan_hexadecimal_literal_(pos)) {
  } else if (scan_octal_literal_(pos)) {
  } else {
    return 0;
  }
  return pos;
}