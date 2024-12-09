TEST(LookupStringInFixedSetTest, Dafsa5EnumerateLanguage) {
  auto language = EnumerateDafsaLanguage(test5::kDafsa);

  std::vector<std::string> expected_language = {
      "aaaam, 0", "aak, 0", "ai, 0", "bbbbn, 0", "bbl, 4", "bj, 4",
  };

  EXPECT_EQ(expected_language, language);
}