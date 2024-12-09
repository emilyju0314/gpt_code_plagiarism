TEST(BitWriterTest, WriteBoth) {
  BitWriter writer;

  // 0xAA is 10101010 in binary. WritBits will write the n least significant
  // bits where n is given as the second parameter.
  writer.WriteBits(0xAA, 1);
  EXPECT_EQ(1U, writer.position());
  writer.WriteBit(1);
  writer.WriteBits(0xAA, 2);
  EXPECT_EQ(4U, writer.position());
  writer.WriteBits(0xAA, 3);
  EXPECT_EQ(7U, writer.position());
  writer.WriteBit(1);
  EXPECT_EQ(8U, writer.position());

  writer.WriteBits(0xAA, 2);
  writer.WriteBit(0);
  EXPECT_EQ(11U, writer.position());

  // Flush should pad the current byte with zero's until it's full.
  writer.Flush();

  // The writer should have 2 bytes now even though we only wrote 10 bits.
  EXPECT_EQ(16U, writer.position());

  // 0 + 1 + 10 + 010 + 1 + 10 + 0 + 00000 (padding) = 0x6580
  EXPECT_THAT(writer.bytes(), testing::ElementsAre(0x65, 0x80));
}