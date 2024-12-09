TEST_P(VerifyNameMatchSimpleTest, ExactEquality) {
  std::string der;
  ASSERT_TRUE(LoadTestData("ascii", value_type(), suffix(), &der));
  EXPECT_TRUE(VerifyNameMatch(SequenceValueFromString(&der),
                              SequenceValueFromString(&der)));

  std::string der_extra_attr;
  ASSERT_TRUE(LoadTestData("ascii", value_type(), suffix() + "-extra_attr",
                           &der_extra_attr));
  EXPECT_TRUE(VerifyNameMatch(SequenceValueFromString(&der_extra_attr),
                              SequenceValueFromString(&der_extra_attr)));

  std::string der_extra_rdn;
  ASSERT_TRUE(LoadTestData("ascii", value_type(), suffix() + "-extra_rdn",
                           &der_extra_rdn));
  EXPECT_TRUE(VerifyNameMatch(SequenceValueFromString(&der_extra_rdn),
                              SequenceValueFromString(&der_extra_rdn)));
}