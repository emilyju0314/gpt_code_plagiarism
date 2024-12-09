TEST_P(VerifyNameMatchNormalizationTest, CollapseWhitespace) {
  std::string normal;
  ASSERT_TRUE(LoadTestData("ascii", value_type(), "unmangled", &normal));
  std::string whitespace;
  ASSERT_TRUE(
      LoadTestData("ascii", value_type(), "extra_whitespace", &whitespace));
  EXPECT_EQ(expected_result(),
            VerifyNameMatch(SequenceValueFromString(&normal),
                            SequenceValueFromString(&whitespace)));
  EXPECT_EQ(expected_result(),
            VerifyNameMatch(SequenceValueFromString(&whitespace),
                            SequenceValueFromString(&normal)));
}