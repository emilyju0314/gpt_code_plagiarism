unsigned Text_Token_Stream::scan_floating_literal_() {
  unsigned pos = 0;
  if (scan_fractional_constant_(pos) > 0) {
    scan_exponent_part_(pos);
    return pos;
  } else if (scan_digit_sequence_(pos)) {
    if (scan_exponent_part_(pos) == 0)
      return 0;
    return pos;
  } else {
    return 0;
  }
}