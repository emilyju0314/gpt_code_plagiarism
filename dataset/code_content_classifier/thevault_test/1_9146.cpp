TEST(Scale, encodeCollectionUint16) {
  std::vector<uint16_t> collection = {1, 2, 3, 4};
  ScaleEncoderStream s;
  ASSERT_NO_THROW((s << collection));
  auto &&out = s.data();
  // clang-format off
  ASSERT_EQ(out,
          (ByteArray{
              16,  // header
            1, 0,  // first item
            2, 0,  // second item
            3, 0,  // third item
            4, 0  // fourth item
              }));
  // clang-format on
}