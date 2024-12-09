TEST(ScaleVariant, DecodeU32Success) {
  ByteArray match = {1, 1, 0, 0, 0};  // uint32_t{1}
  ScaleDecoderStream s(match);
  boost::variant<uint8_t, uint32_t> val{};
  ASSERT_NO_THROW(s >> val);
  sgns::visit_in_place(
      val, [](uint32_t v) { ASSERT_EQ(v, 1); }, [](uint8_t v) { FAIL(); });
}