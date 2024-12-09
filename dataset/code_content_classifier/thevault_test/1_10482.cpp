TEST(ValidateMyanmarTest, BadMyanmarWords) {
  std::string str = "က်န္းမာေရး";
  std::vector<std::string> glyphs;
  EXPECT_FALSE(NormalizeCleanAndSegmentUTF8(UnicodeNormMode::kNFC, OCRNorm::kNone,
                                            GraphemeNormMode::kCombined, true, str.c_str(),
                                            &glyphs));
  std::string result;
  EXPECT_FALSE(NormalizeUTF8String(UnicodeNormMode::kNFC, OCRNorm::kNone, GraphemeNorm::kNormalize,
                                   str.c_str(), &result));
  // It works if the grapheme normalization is turned off.
  EXPECT_TRUE(NormalizeUTF8String(UnicodeNormMode::kNFC, OCRNorm::kNone, GraphemeNorm::kNone,
                                  str.c_str(), &result));
  EXPECT_EQ(str, result);
  str = "ခုႏွစ္";
  EXPECT_FALSE(NormalizeCleanAndSegmentUTF8(UnicodeNormMode::kNFC, OCRNorm::kNone,
                                            GraphemeNormMode::kGlyphSplit, true, str.c_str(),
                                            &glyphs));
  EXPECT_FALSE(NormalizeUTF8String(UnicodeNormMode::kNFC, OCRNorm::kNone, GraphemeNorm::kNormalize,
                                   str.c_str(), &result));
  // It works if the grapheme normalization is turned off.
  EXPECT_TRUE(NormalizeUTF8String(UnicodeNormMode::kNFC, OCRNorm::kNone, GraphemeNorm::kNone,
                                  str.c_str(), &result));
  EXPECT_EQ(str, result);
}