static std::string to_name(uint64_t i) {

  // 13 is enough to hold a 64 bit int.
  char c[16];

  size_t idx = 0;

  while(idx < 16) {
    c[idx] = 'A' + char(i % 26);
    ++idx;
    if(i < 26) break;
    i /= 26;
  }

  return std::string(c, idx);
}