TEST(ValidateKhmerTest, GoodKhmerWords) {
  std::string str = "ព័ត៏មានប្លែកៗ";
  ExpectGraphemeModeResults(str, UnicodeNormMode::kNFC, 13, 12, 7, str);
  str = "ទំនុកច្រៀង";
  ExpectGraphemeModeResults(str, UnicodeNormMode::kNFC, 10, 9, 5, str);
  str = "កាលីហ្វូញ៉ា";
  ExpectGraphemeModeResults(str, UnicodeNormMode::kNFC, 11, 10, 4, str);
  str = "ចាប់ពីផ្លូវ";
  ExpectGraphemeModeResults(str, UnicodeNormMode::kNFC, 11, 10, 5, str);
}