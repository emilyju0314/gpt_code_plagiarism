TEST_P(VerifyNameMatchSimpleTest, ExtraAttrDoesNotMatch) {
  std::string der;
  ASSERT_TRUE(LoadTestData("ascii", value_type(), suffix(), &der));
  std::string der_extra_attr;
  ASSERT_TRUE(LoadTestData("ascii", value_type(), suffix() + "-extra_attr",
                           &der_extra_attr));
  EXPECT_FALSE(VerifyNameMatch(SequenceValueFromString(&der),
                               SequenceValueFromString(&der_extra_attr)));
  EXPECT_FALSE(VerifyNameMatch(SequenceValueFromString(&der_extra_attr),
                               SequenceValueFromString(&der)));
}