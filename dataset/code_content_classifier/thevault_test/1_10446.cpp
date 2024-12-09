TEST(ValidateIndicTest, SubGraphemes) {
  std::string str = "\u0d3e"; // AA
  std::string dest;
  EXPECT_FALSE(NormalizeUTF8String(UnicodeNormMode::kNFC, OCRNorm::kNone, GraphemeNorm::kNormalize,
                                   str.c_str(), &dest))
      << PrintString32WithUnicodes(str);
  EXPECT_TRUE(NormalizeUTF8String(UnicodeNormMode::kNFC, OCRNorm::kNone, GraphemeNorm::kNone,
                                  str.c_str(), &dest))
      << PrintString32WithUnicodes(str);
  EXPECT_EQ(dest, str);
}