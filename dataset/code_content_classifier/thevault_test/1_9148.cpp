TEST(Scale, encodeCollectionUint64) {
  std::vector<uint64_t> collection = {506097522914230528ull,
                                      1084818905618843912ull};
  ScaleEncoderStream s;
  ASSERT_NO_THROW((s << collection));
  auto &&out = s.data();
  // clang-format off
  ASSERT_EQ(out,
            (ByteArray{
                    8,                // header
                    0, 1, 2, 3,        // first item
                    4, 5, 6, 7,        // second item
                    8, 9, 0xA, 0xB,    // third item
                    0xC, 0xD, 0xE, 0xF // fourth item
            }));
  // clang-format on
}