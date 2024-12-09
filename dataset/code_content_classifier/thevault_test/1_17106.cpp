TEST(ParseValuesTest, ParseBitStringSevenOneBits) {
  const uint8_t kData[] = {0x01, 0xFE};

  BitString bit_string;
  ASSERT_TRUE(ParseBitString(Input(kData), &bit_string));

  EXPECT_EQ(1u, bit_string.unused_bits());
  EXPECT_EQ(1u, bit_string.bytes().Length());
  EXPECT_EQ(0xFE, bit_string.bytes().UnsafeData()[0]);

  EXPECT_TRUE(bit_string.AssertsBit(0));
  EXPECT_TRUE(bit_string.AssertsBit(1));
  EXPECT_TRUE(bit_string.AssertsBit(2));
  EXPECT_TRUE(bit_string.AssertsBit(3));
  EXPECT_TRUE(bit_string.AssertsBit(4));
  EXPECT_TRUE(bit_string.AssertsBit(5));
  EXPECT_TRUE(bit_string.AssertsBit(6));
  EXPECT_FALSE(bit_string.AssertsBit(7));
  EXPECT_FALSE(bit_string.AssertsBit(8));
}