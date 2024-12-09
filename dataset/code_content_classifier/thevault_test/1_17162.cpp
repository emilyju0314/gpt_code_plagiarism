TEST(BitWriterTest, WriteBits) {
  BitWriter writer;

  // 0xAA is 10101010 in binary. WritBits will write the n least significant
  // bits where n is given as the second parameter.
  writer.WriteBits(0xAA, 1);
  EXPECT_EQ(1U, writer.position());
  writer.WriteBits(0xAA, 2);
  EXPECT_EQ(3U, writer.position());
  writer.WriteBits(0xAA, 3);
  EXPECT_EQ(6U, writer.position());
  writer.WriteBits(0xAA, 2);
  EXPECT_EQ(8U, writer.position());
  writer.WriteBits(0xAA, 2);
  EXPECT_EQ(10U, writer.position());

  // Flush should pad the current byte with zero's until it's full.
  writer.Flush();

  // The writer should have 2 bytes now even though we only wrote 10 bits.
  EXPECT_EQ(16U, writer.position());

  // 0 + 10 + 010 + 10 + 10 + 000000 (padding) = 0x4A80
  EXPECT_THAT(writer.bytes(), testing::ElementsAre(0x4A, 0x80));
}