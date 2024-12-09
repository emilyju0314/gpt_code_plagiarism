TEST(HuffmanBuilderTest, OptimalCodeOrder) {
  HuffmanBuilder builder;
  HuffmanRepresentationTable encoding;
  for (uint8_t i = 0; i <= 127; i++) {
    for (uint8_t j = 0; j <= (i + 1); j++) {
      builder.RecordUsage(i);
    }
  }

  encoding = builder.ToTable();
  for (uint8_t i = 0; i <= 127; i++) {
    // The representation for |i| should be longer or have the same length as
    // all following representations because they have a higher frequency and
    // therefor should never get a longer representation.
    for (uint8_t j = i; j <= 127; j++) {
      // A representation for the values should exist in the table.
      ASSERT_NE(encoding.find(i), encoding.cend());
      ASSERT_NE(encoding.find(j), encoding.cend());

      EXPECT_GE(encoding[i].number_of_bits, encoding[j].number_of_bits);
    }
  }
}