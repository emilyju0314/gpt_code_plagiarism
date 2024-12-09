bool Token::fmatch(Token const& rhs) const {
  int count = length();
  if (count == rhs.length()) {
    const unsigned char* read1 = (const unsigned char*)this->m_pzTokenStart;
    const unsigned char* read2 = (const unsigned char*)rhs.m_pzTokenStart;
    while (count) {
      int c1 = *read1++;
      int c2 = *read2++;
      int r = c1 ^ c2;
      if (r != 0 && (r ^ 0x20) != 0) {
        return false;
      }
      --count;
    }
    return true;
  }
  return false;
}