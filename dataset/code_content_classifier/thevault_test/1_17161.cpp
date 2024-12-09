TEST(BitWriterTest, WriteBit) {
  BitWriter writer;

  EXPECT_EQ(0U, writer.position());
  EXPECT_EQ(0U, writer.bytes().size());

  writer.WriteBit(0);

  EXPECT_EQ(1U, writer.position());

  writer.WriteBit(1);
  writer.WriteBit(0);
  writer.WriteBit(1);
  writer.WriteBit(0);
  writer.WriteBit(1);
  writer.WriteBit(0);
  writer.WriteBit(1);

  EXPECT_EQ(8U, writer.position());

  writer.WriteBit(0);

  EXPECT_EQ(9U, writer.position());

  writer.WriteBit(1);
  writer.WriteBit(0);

  EXPECT_EQ(11U, writer.position());

  // Flush should pad the current byte with zero's until it's full.
  writer.Flush();

  // The writer should have 2 bytes now even though we only wrote 11 bits.
  EXPECT_EQ(16U, writer.position());

  // 0 + 1 + 0 + 1 + 0 + 1 + 0 + 1 + 0 + 1 + 0  + 00000 (padding) = 0x5540.
  EXPECT_THAT(writer.bytes(), testing::ElementsAre(0x55, 0x40));
}