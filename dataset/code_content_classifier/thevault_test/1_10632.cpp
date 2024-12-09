TEST(ValidatorTest, Idempotency) {
  std::vector<char32> str1({0xd24, 0xd23, 0xd32, 0xd4d, '\'', 0x200d, 0x200c, 0x200d, 0x200c});
  std::vector<char32> str2({0xd24, 0xd23, 0xd32, 0xd4d, 0x200c, 0x200d, 0x200c, 0x200d, '\''});
  std::vector<std::vector<char32>> result1, result2, result3, result4;
  EXPECT_TRUE(
      Validator::ValidateCleanAndSegment(GraphemeNormMode::kSingleString, true, str1, &result1));
  EXPECT_TRUE(Validator::ValidateCleanAndSegment(GraphemeNormMode::kSingleString, true, result1[0],
                                                 &result2));
  EXPECT_EQ(result1.size(), result2.size());
  EXPECT_THAT(result2[0], testing::ElementsAreArray(result1[0]));
  EXPECT_TRUE(
      Validator::ValidateCleanAndSegment(GraphemeNormMode::kSingleString, true, str2, &result3));
  EXPECT_TRUE(Validator::ValidateCleanAndSegment(GraphemeNormMode::kSingleString, true, result3[0],
                                                 &result4));
  EXPECT_EQ(result3.size(), result4.size());
  EXPECT_THAT(result4[0], testing::ElementsAreArray(result3[0]));
}