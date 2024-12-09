std::vector<uint8_t>
    bits_to_bytes(const std::vector<uint8_t>& in)
    {
      if (in.empty()) {
        return in;
      }
      const size_t len = in.size();
      std::vector<uint8_t> ret;
      for (size_t c = 0; c < len; c += 8) {
        ret.push_back(bits_to_byte(&in[c], &in[std::min(len, c+8)]));
      }
      return ret;
    }