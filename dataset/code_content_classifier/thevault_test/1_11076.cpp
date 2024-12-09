TEST(ValidateKhmerTest, BadKhmerWords) {
  std::string result;
  // Multiple dependent vowels not allowed
  std::string str = "\u1796\u17b6\u17b7";
  EXPECT_FALSE(NormalizeUTF8String(UnicodeNormMode::kNFC, OCRNorm::kNone, GraphemeNorm::kNormalize,
                                   str.c_str(), &result));
  // Multiple shifters not allowed
  str = "\u1798\u17c9\u17ca";
  EXPECT_FALSE(NormalizeUTF8String(UnicodeNormMode::kNFC, OCRNorm::kNone, GraphemeNorm::kNormalize,
                                   str.c_str(), &result));
  // Multiple signs not allowed
  str = "\u1780\u17b6\u17cb\u17cd";
  EXPECT_FALSE(NormalizeUTF8String(UnicodeNormMode::kNFC, OCRNorm::kNone, GraphemeNorm::kNormalize,
                                   str.c_str(), &result));
}