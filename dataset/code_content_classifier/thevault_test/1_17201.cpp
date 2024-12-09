TEST(VerifyNameMatchRDNSorting, DuplicateTypes) {
  std::string a;
  ASSERT_TRUE(LoadTestData("ascii", "mixed", "rdn_dupetype_sorting_1", &a));
  std::string b;
  ASSERT_TRUE(LoadTestData("ascii", "mixed", "rdn_dupetype_sorting_2", &b));
  EXPECT_TRUE(VerifyNameMatch(SequenceValueFromString(&a),
                              SequenceValueFromString(&b)));
  EXPECT_TRUE(VerifyNameMatch(SequenceValueFromString(&b),
                              SequenceValueFromString(&a)));
}