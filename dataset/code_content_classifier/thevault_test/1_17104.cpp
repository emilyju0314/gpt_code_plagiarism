TEST(ParseValuesTest, ParseBitStringEmptyOneUnusedBit) {
  const uint8_t kData[] = {0x01};

  BitString bit_string;
  EXPECT_FALSE(ParseBitString(Input(kData), &bit_string));
}