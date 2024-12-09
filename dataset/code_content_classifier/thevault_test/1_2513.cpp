bool is_big_endian() {
  union {
    uint32_t i;
    std::array<char, 4> c;
  } data = {0x01020304};

  return data.c[0] == 1;
}