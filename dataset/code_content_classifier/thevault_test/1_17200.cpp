TEST(VerifyNameMatchRDNSorting, Simple) {
  std::string a;
  ASSERT_TRUE(LoadTestData("ascii", "PRINTABLESTRING", "rdn_sorting_1", &a));
  std::string b;
  ASSERT_TRUE(LoadTestData("ascii", "PRINTABLESTRING", "rdn_sorting_2", &b));
  EXPECT_TRUE(VerifyNameMatch(SequenceValueFromString(&a),
                              SequenceValueFromString(&b)));
  EXPECT_TRUE(VerifyNameMatch(SequenceValueFromString(&b),
                              SequenceValueFromString(&a)));
}