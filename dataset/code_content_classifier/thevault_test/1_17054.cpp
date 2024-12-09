TEST(HuffmanBuilderTest, NoMissingInputs) {
  HuffmanBuilder builder;
  HuffmanRepresentationTable encoding;
  for (uint8_t i = 0; i <= 127; i++) {
    if (i % 2) {
      for (uint8_t j = 0; j <= i % 5; j++) {
        builder.RecordUsage(i);
      }
    }
  }

  encoding = builder.ToTable();
  for (uint8_t i = 0; i <= 127; i++) {
    if (i % 2) {
      EXPECT_NE(encoding.find(i), encoding.cend());
    } else {
      EXPECT_EQ(encoding.find(i), encoding.cend());
    }
  }
}