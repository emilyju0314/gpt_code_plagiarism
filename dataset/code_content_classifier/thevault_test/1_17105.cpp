TEST(ParseValuesTest, ParseBitStringNonEmptyTooManyUnusedBits) {
  const uint8_t kData[] = {0x08, 0x00};

  BitString bit_string;
  EXPECT_FALSE(ParseBitString(Input(kData), &bit_string));
}