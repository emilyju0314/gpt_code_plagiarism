TEST(Scale, decodePair) {
  ByteArray bytes = {1, 2, 0, 0, 0};
  ScaleDecoderStream s(bytes);
  using pair_type = std::pair<uint8_t, uint32_t>;
  pair_type pair{};
  ASSERT_NO_THROW((s >> pair));
  ASSERT_EQ(pair.first, 1);
  ASSERT_EQ(pair.second, 2);
}