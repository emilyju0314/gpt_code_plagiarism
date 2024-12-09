LcePrezza(uint64_t * const text, size_t const size)
  : text_length_in_bytes_(size),
    text_length_in_blocks_(size / 8 + (size % 8 == 0 ? 0 : 1)),
    fingerprints_(text),
    power_table_(new uint64_t[((int) std::log2(text_length_in_blocks_)) + 6]) {
      calculateFingerprints();
      calculatePowers();
  }