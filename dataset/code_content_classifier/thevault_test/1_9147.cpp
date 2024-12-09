TEST(Scale, encodeCollectionUint32) {
  std::vector<uint32_t> collection = {50462976, 117835012, 185207048,
                                      252579084};
  ScaleEncoderStream s;
  ASSERT_NO_THROW((s << collection));
  auto &&out = s.data();
  // clang-format off
  ASSERT_EQ(out,
            (ByteArray{
                    16,                // header
                    0, 1, 2, 3,        // first item
                    4, 5, 6, 7,        // second item
                    8, 9, 0xA, 0xB,    // third item
                    0xC, 0xD, 0xE, 0xF // fourth item
            }));
  // clang-format on
}