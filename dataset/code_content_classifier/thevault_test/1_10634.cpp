void BoxChar::GetDirection(int *num_rtl, int *num_ltr) const {
  // Convert the unichar to UTF32 representation
  std::vector<char32> uni_vector = UNICHAR::UTF8ToUTF32(ch_.c_str());
  if (uni_vector.empty()) {
    tprintf("Illegal utf8 in boxchar string:%s = ", ch_.c_str());
    for (char c : ch_) {
      tprintf(" 0x%x", c);
    }
    tprintf("\n");
    return;
  }
  for (char32 ch : uni_vector) {
    UCharDirection dir = u_charDirection(ch);
    if (dir == U_RIGHT_TO_LEFT || dir == U_RIGHT_TO_LEFT_ARABIC || dir == U_RIGHT_TO_LEFT_ISOLATE) {
      ++*num_rtl;
    } else if ((dir == U_ARABIC_NUMBER) ||
               (dir != U_DIR_NON_SPACING_MARK && dir != U_BOUNDARY_NEUTRAL)) {
      ++*num_ltr;
    }
  }
}