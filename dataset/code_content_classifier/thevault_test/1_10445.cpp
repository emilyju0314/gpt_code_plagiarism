TEST(ValidateIndicTest, OnlyOneDependentVowel) {
  std::string str = "\u0d15\u0d3e\u0d42"; // KA AA UU
  std::string dest;
  EXPECT_FALSE(NormalizeUTF8String(UnicodeNormMode::kNFC, OCRNorm::kNone, GraphemeNorm::kNormalize,
                                   str.c_str(), &dest))
      << PrintString32WithUnicodes(str);
}