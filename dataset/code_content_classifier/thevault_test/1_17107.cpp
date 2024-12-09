TEST(ParseValuesTest, ParseBitStringSevenOneBitsUnusedBitIsOne) {
  const uint8_t kData[] = {0x01, 0xFF};

  BitString bit_string;
  EXPECT_FALSE(ParseBitString(Input(kData), &bit_string));
}