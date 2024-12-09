TEST(FormatPrintfTemplateAndSet, HugeResult) {
  constexpr int kLength = 100 * 1000;
  const std::string kParameter(kLength, 'a');
  std::string formatted;
  FormatPrintfTemplateAndSet(&formatted, "%s", kParameter.c_str());
  EXPECT_EQ(formatted, kParameter);
}