void BoxChar::ReverseUnicodesInBox() {
  std::vector<char32> unicodes = UNICHAR::UTF8ToUTF32(ch_.c_str());
  std::reverse(unicodes.begin(), unicodes.end());
  ch_ = UNICHAR::UTF32ToUTF8(unicodes);
}