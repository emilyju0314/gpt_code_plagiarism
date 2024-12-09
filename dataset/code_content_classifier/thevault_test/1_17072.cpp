TEST(LookupStringInFixedSetTest, Dafsa1EnumerateLanguage) {
  auto language = EnumerateDafsaLanguage(test1::kDafsa);

  // These are the lines of effective_tld_names_unittest1.gperf, in sorted
  // order.
  std::vector<std::string> expected_language = {
      "ac.jp, 0",       "b.c, 1",     "bar.baz.com, 0", "bar.jp, 2",
      "baz.bar.jp, 2",  "c, 2",       "jp, 0",          "no, 0",
      "pref.bar.jp, 1", "priv.no, 4", "private, 4",     "xn--fiqs8s, 0",
  };

  EXPECT_EQ(expected_language, language);
}