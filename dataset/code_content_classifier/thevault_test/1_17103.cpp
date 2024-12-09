TEST(ParseValuesTest, ParseBitStringEmptyNoUnusedBits) {
  const uint8_t kData[] = {0x00};

  BitString bit_string;
  ASSERT_TRUE(ParseBitString(Input(kData), &bit_string));

  EXPECT_EQ(0u, bit_string.unused_bits());
  EXPECT_EQ(0u, bit_string.bytes().Length());

  EXPECT_FALSE(bit_string.AssertsBit(0));
  EXPECT_FALSE(bit_string.AssertsBit(1));
  EXPECT_FALSE(bit_string.AssertsBit(3));
}