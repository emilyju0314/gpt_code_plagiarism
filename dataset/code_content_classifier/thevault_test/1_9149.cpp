TEST(Scale, encodeVeryLongCollectionUint8) {
  auto length = 1048576;  // 2^20
  std::vector<uint8_t> collection;
  collection.reserve(length);

  for (auto i = 0; i < length; ++i) {
    collection.push_back(i % 256);
  }

  ScaleEncoderStream s;
  ASSERT_NO_THROW((s << collection));
  auto &&out = s.data();
  ASSERT_EQ(out.size(), (length + 4));
  // header takes 4 bytes,
  // first byte == (4-4) + 3 = 3,
  // which means that number of items requires 4 bytes
  // 3 next bytes are 0, and the last 4-th == 2^6 == 64
  // which is compact-encoded value 2^14 = 16384
  auto stream = ScaleDecoderStream(gsl::make_span(out));
  CompactInteger bi{};
  ASSERT_NO_THROW(stream >> bi);
  ASSERT_EQ(bi, 1048576);

  // now only 1048576 bytes left in stream
  ASSERT_EQ(stream.hasMore(1048576), true);
  ASSERT_EQ(stream.hasMore(1048576 + 1), false);

  for (auto i = 0; i < length; ++i) {
    uint8_t byte{0u};
    ASSERT_NO_THROW((stream >> byte));
    ASSERT_EQ(byte, i % 256);
  }

  ASSERT_EQ(stream.hasMore(1), false);
}