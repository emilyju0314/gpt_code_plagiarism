TEST(SchemeHostPortMatcherRuleTest, ParseBracketedCIDR_IPv6) {
  std::unique_ptr<SchemeHostPortMatcherRule> rule =
      SchemeHostPortMatcherRule::FromUntrimmedRawString("[a:b:c:d::]/48");
  EXPECT_EQ(nullptr, rule);
}