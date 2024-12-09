TEST_F(QuicheEndianTest, Portable) {
  EXPECT_EQ(k16BitSwappedTestData,
            QuicheEndian::PortableByteSwap(k16BitTestData));
  EXPECT_EQ(k32BitSwappedTestData,
            QuicheEndian::PortableByteSwap(k32BitTestData));
  EXPECT_EQ(k64BitSwappedTestData,
            QuicheEndian::PortableByteSwap(k64BitTestData));
}