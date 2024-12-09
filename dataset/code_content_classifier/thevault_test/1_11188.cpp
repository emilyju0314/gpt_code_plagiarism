TEST_F(BitVectorTest, TestNextSetBit) {
  BitVector bv;
  for (int spacing = 1; spacing <= 5; ++spacing) {
    SetBitPattern(0, 256, spacing, &bv);
    ExpectCorrectBits(bv);
  }
}