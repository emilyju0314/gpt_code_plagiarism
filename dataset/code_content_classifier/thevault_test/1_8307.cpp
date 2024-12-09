uint8_t
    bits_to_byte(const char* b, const char* e)
    {
      uint8_t t = 0;
      const char* p = b;
      for (int c = 0; p < e; c++) {
        t <<= 1;
        if (*p++) {
          t |= 1;
        }
      }
      if (e - b < 8) {
        t <<= (8- (e-b));
      }
      return t;
    }