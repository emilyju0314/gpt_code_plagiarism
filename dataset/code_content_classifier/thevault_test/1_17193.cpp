TEST_P(VerifyNameMatchSimpleTest, DupeAttrDoesNotMatch) {
  std::string der_dupe_attr;
  ASSERT_TRUE(LoadTestData("ascii", value_type(), suffix() + "-dupe_attr",
                           &der_dupe_attr));
  std::string der_extra_attr;
  ASSERT_TRUE(LoadTestData("ascii", value_type(), suffix() + "-extra_attr",
                           &der_extra_attr));
  EXPECT_FALSE(VerifyNameMatch(SequenceValueFromString(&der_dupe_attr),
                               SequenceValueFromString(&der_extra_attr)));
  EXPECT_FALSE(VerifyNameMatch(SequenceValueFromString(&der_extra_attr),
                               SequenceValueFromString(&der_dupe_attr)));
  // However, the name with a dupe attribute should match itself.
  EXPECT_TRUE(VerifyNameMatch(SequenceValueFromString(&der_dupe_attr),
                              SequenceValueFromString(&der_dupe_attr)));
}