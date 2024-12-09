TEST(ValidateMyanmarTest, GoodMyanmarWords) {
  std::string str = "လျှာကသိသည် "; // No viramas in this one.
  ExpectGraphemeModeResults(str, UnicodeNormMode::kNFC, 11, 11, 5, str);
  str = "တုန္လႈပ္မႈ ";
  ExpectGraphemeModeResults(str, UnicodeNormMode::kNFC, 11, 9, 4, str);
}