TEST(ValidateIndicTest, SinhalaRakaransaya) {
  std::string str = "\u0d9a\u0dca\u200d\u0dbb"; // KA Virama ZWJ Rayanna
  std::string dest;
  EXPECT_TRUE(NormalizeUTF8String(UnicodeNormMode::kNFC, OCRNorm::kNone, GraphemeNorm::kNormalize,
                                  str.c_str(), &dest))
      << PrintString32WithUnicodes(str);
  EXPECT_EQ(dest, str);
  std::vector<std::string> glyphs;
  EXPECT_TRUE(NormalizeCleanAndSegmentUTF8(UnicodeNormMode::kNFC, OCRNorm::kNone,
                                           GraphemeNormMode::kGlyphSplit, true, str.c_str(),
                                           &glyphs));
  EXPECT_EQ(glyphs.size(), 2);
  EXPECT_EQ(glyphs[1], std::string("\u0dca\u200d\u0dbb"));
  // Can be followed by a dependent vowel.
  str += "\u0dd9"; // E
  EXPECT_TRUE(NormalizeUTF8String(UnicodeNormMode::kNFC, OCRNorm::kNone, GraphemeNorm::kNormalize,
                                  str.c_str(), &dest))
      << PrintString32WithUnicodes(str);
  EXPECT_EQ(dest, str);
}