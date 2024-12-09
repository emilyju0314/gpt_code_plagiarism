TEST(Scale, encodeOptional) {
  // most simple case
  {
    ScaleEncoderStream s;
    ASSERT_NO_THROW((s << boost::optional<uint8_t>{boost::none}));
    ASSERT_EQ(s.data(), (ByteArray{0}));
  }

  // encode existing uint8_t
  {
    ScaleEncoderStream s;
    ASSERT_NO_THROW((s << boost::optional<uint8_t>{1}));
    ASSERT_EQ(s.data(), (ByteArray{1, 1}));
  }

  // encode negative int8_t
  {
    ScaleEncoderStream s;
    ASSERT_NO_THROW((s << boost::optional<int8_t>{-1}));
    ASSERT_EQ(s.data(), (ByteArray{1, 255}));
  }

  // encode non-existing uint16_t
  {
    ScaleEncoderStream s;
    ASSERT_NO_THROW((s << boost::optional<uint16_t>{boost::none}));
    ASSERT_EQ(s.data(), (ByteArray{0}));
  }

  // encode existing uint16_t
  {
    ScaleEncoderStream s;
    ASSERT_NO_THROW((s << boost::optional<uint16_t>{511}));
    ASSERT_EQ(s.data(), (ByteArray{1, 255, 1}));
  }

  // encode existing uint32_t
  {
    ScaleEncoderStream s;
    ASSERT_NO_THROW((s << boost::optional<uint32_t>{67305985}));
    ASSERT_EQ(s.data(), (ByteArray{1, 1, 2, 3, 4}));
  }
}