TEST(VerifyNameMatchInvalidDataTest, FailOnInvalidPrintableStringChars) {
  std::string der;
  ASSERT_TRUE(LoadTestData("ascii", "PRINTABLESTRING", "unmangled", &der));
  // Find a known location inside a PrintableString in the DER-encoded data.
  size_t replace_location = der.find("0123456789");
  ASSERT_NE(std::string::npos, replace_location);
  for (int c = 0; c < 256; ++c) {
    SCOPED_TRACE(base::NumberToString(c));
    if (base::IsAsciiAlpha(c) || base::IsAsciiDigit(c))
      continue;
    switch (c) {
      case ' ':
      case '\'':
      case '(':
      case ')':
      case '*':
      case '+':
      case ',':
      case '-':
      case '.':
      case '/':
      case ':':
      case '=':
      case '?':
        continue;
    }
    der.replace(replace_location, 1, 1, c);
    // Verification should fail due to the invalid character.
    EXPECT_FALSE(VerifyNameMatch(SequenceValueFromString(&der),
                                 SequenceValueFromString(&der)));
    std::string normalized_der;
    CertErrors errors;
    EXPECT_FALSE(
        NormalizeName(SequenceValueFromString(&der), &normalized_der, &errors));
  }
}