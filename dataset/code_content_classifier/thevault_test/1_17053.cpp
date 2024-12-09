TEST(HuffmanBuilderTest, NoPrefixCollision) {
  HuffmanBuilder builder;
  HuffmanRepresentationTable encoding;
  for (uint8_t i = 0; i <= 127; i++) {
    // Make sure all values have an identical count to at least some other
    // values.
    for (uint8_t j = 0; j <= i % 32; j++) {
      builder.RecordUsage(i);
    }
  }

  encoding = builder.ToTable();
  for (uint8_t i = 0; i <= 127; i++) {
    // There should never exist a representation that is a prefix for, or
    // identical to, another.
    uint32_t mask = 0;
    for (uint32_t k = 0; k <= encoding[i].number_of_bits; k++) {
      mask = (mask << 1) | 1;
    }
    mask = mask << (32 - encoding[i].number_of_bits);

    for (uint8_t j = 0; j <= 127; j++) {
      if (i == j) {
        continue;
      }

      uint32_t aligned_i = encoding[i].bits
                           << (32 - encoding[i].number_of_bits);
      uint32_t aligned_j = encoding[j].bits
                           << (32 - encoding[j].number_of_bits);
      EXPECT_NE(aligned_i, aligned_j & mask);
    }
  }
}