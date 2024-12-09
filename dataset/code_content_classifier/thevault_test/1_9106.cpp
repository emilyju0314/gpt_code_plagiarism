TEST(ScaleDecoderStreamTest, HasMoreTest) {
  auto bytes = ByteArray{0, 1};
  auto stream = ScaleDecoderStream{bytes};

  ASSERT_TRUE(stream.hasMore(0));
  ASSERT_TRUE(stream.hasMore(1));
  ASSERT_TRUE(stream.hasMore(2));
  ASSERT_FALSE(stream.hasMore(3));

  ASSERT_NO_THROW(stream.nextByte());
  ASSERT_TRUE(stream.hasMore(1));
  ASSERT_FALSE(stream.hasMore(2));

  ASSERT_NO_THROW(stream.nextByte());
  ASSERT_FALSE(stream.hasMore(1));

  ASSERT_ANY_THROW(stream.nextByte());
}