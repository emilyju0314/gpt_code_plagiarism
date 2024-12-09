TEST(SchemeHostPortMatcherTest, DoesNotMimicProxyBypassRules) {
  // Should not parse <-loopback> as its own rule (will treat it as a hostname
  // rule).
  SchemeHostPortMatcher matcher =
      SchemeHostPortMatcher::FromRawString("<-loopback>");
  EXPECT_EQ(1u, matcher.rules().size());
  EXPECT_EQ("<-loopback>", matcher.rules().front()->ToString());

  // Should not parse <local> as its own rule (will treat it as a hostname
  // rule).
  matcher = SchemeHostPortMatcher::FromRawString("<local>");
  EXPECT_EQ(1u, matcher.rules().size());
  EXPECT_EQ("<local>", matcher.rules().front()->ToString());

  // Should not implicitly match localhost or link-local addresses.
  matcher = SchemeHostPortMatcher::FromRawString("www.example.com");
  EXPECT_EQ(SchemeHostPortMatcherResult::kNoMatch,
            matcher.Evaluate(GURL("http://localhost")));
  EXPECT_EQ(SchemeHostPortMatcherResult::kNoMatch,
            matcher.Evaluate(GURL("http://169.254.1.1")));
}