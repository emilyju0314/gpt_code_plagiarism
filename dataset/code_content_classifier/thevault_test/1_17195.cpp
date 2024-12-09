TEST_P(VerifyNameMatchNormalizationTest, CaseInsensitivity) {
  std::string normal;
  ASSERT_TRUE(LoadTestData("ascii", value_type(), "unmangled", &normal));
  std::string case_swap;
  ASSERT_TRUE(LoadTestData("ascii", value_type(), "case_swap", &case_swap));
  EXPECT_EQ(expected_result(),
            VerifyNameMatch(SequenceValueFromString(&normal),
                            SequenceValueFromString(&case_swap)));
  EXPECT_EQ(expected_result(),
            VerifyNameMatch(SequenceValueFromString(&case_swap),
                            SequenceValueFromString(&normal)));
}