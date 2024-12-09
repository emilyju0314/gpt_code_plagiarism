TEST(Scale, DecodeOptionalBoolFail) {
  auto bytes = ByteArray{0, 1, 2, 3};

  EXPECT_OUTCOME_FALSE_2(err, decode<FourOptBools>(bytes))
  ASSERT_EQ(err.value(), static_cast<int>(DecodeError::UNEXPECTED_VALUE));
}