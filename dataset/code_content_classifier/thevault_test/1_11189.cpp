TEST_F(BitVectorTest, TestNumSetBits) {
  BitVector bv;
  for (int byte = 0; byte < 256; ++byte) {
    SetBitPattern(byte, byte + 1, 1, &bv);
    ExpectCorrectBits(bv);
  }
}