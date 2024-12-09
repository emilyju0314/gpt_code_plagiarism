TEST(ScaleCompactTest, EncodeNegativeIntegerFails) {
  CompactInteger v(-1);
  ScaleEncoderStream out{};
  ASSERT_ANY_THROW((out << v));
  ASSERT_EQ(out.data().size(), 0);  // nothing was written to buffer
}