TEST(Scale, compactDecodeBigIntegerError) {
  auto bytes = ByteArray{255, 255, 255, 255};
  EXPECT_OUTCOME_FALSE_2(err, decode<CompactInteger>(bytes));

  ASSERT_EQ(err.value(),
            static_cast<int>(sgns::scale::DecodeError::NOT_ENOUGH_DATA));
}