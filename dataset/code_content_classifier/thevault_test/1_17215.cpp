void IoTest::ReadStuffLarge(ZeroCopyInputStream* input) {
  ReadString(input, "Hello world!\nSome text.  ");
  EXPECT_TRUE(input->Skip(5));
  ReadString(input, "blah.");
  EXPECT_TRUE(input->Skip(100000 - 10));
  ReadString(input, std::string(10, 'x') + std::string(100000 - 20000, 'y'));
  EXPECT_TRUE(input->Skip(20000 - 10));
  ReadString(input, "yyyyyyyyyy01234567890123456789");

  EXPECT_EQ(input->ByteCount(), 200055);

  uint8 byte;
  EXPECT_EQ(ReadFromInput(input, &byte, 1), 0);
}