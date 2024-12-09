TEST(LookupStringInFixedSetTest, Dafsa6EnumerateLanguage) {
  auto language = EnumerateDafsaLanguage(test6::kDafsa);

  std::vector<std::string> expected_language = {
      "ia, 0", "jb, 4", "kaa, 0", "lbb, 4", "maaaa, 0", "nbbbb, 0",
  };

  EXPECT_EQ(expected_language, language);
}