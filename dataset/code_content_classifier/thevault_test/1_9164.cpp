TEST(ScaleTest, EncodeOptionalBoolSuccess) {
  std::vector<boost::optional<bool>> values = {true, false, boost::none};
  ScaleEncoderStream s;
  for (auto &&v : values) {
    ASSERT_NO_THROW((s << v));
  }
  ASSERT_EQ(s.data(), (ByteArray{2, 1, 0}));
}