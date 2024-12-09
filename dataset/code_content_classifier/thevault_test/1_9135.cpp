TEST_P(CompactTest, DecodeSuccess) {
  const auto &[value_match, bytes] = GetParam();
  ScaleDecoderStream s(gsl::make_span(bytes));
  CompactInteger v{};
  ASSERT_NO_THROW(s >> v);
  ASSERT_EQ(v, value_match);
}