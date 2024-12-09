TEST(Scale, encodePair) {
  uint8_t v1 = 1;
  uint32_t v2 = 2;

  ScaleEncoderStream s;
  ASSERT_NO_THROW((s << std::make_pair(v1, v2)));
  ASSERT_EQ(s.data(), (ByteArray{1, 2, 0, 0, 0}));
}