TEST_P(VerifyNameMatchSimpleTest, ExtraRdnDoesNotMatch) {
  std::string der;
  ASSERT_TRUE(LoadTestData("ascii", value_type(), suffix(), &der));
  std::string der_extra_rdn;
  ASSERT_TRUE(LoadTestData("ascii", value_type(), suffix() + "-extra_rdn",
                           &der_extra_rdn));
  EXPECT_FALSE(VerifyNameMatch(SequenceValueFromString(&der),
                               SequenceValueFromString(&der_extra_rdn)));
  EXPECT_FALSE(VerifyNameMatch(SequenceValueFromString(&der_extra_rdn),
                               SequenceValueFromString(&der)));
}