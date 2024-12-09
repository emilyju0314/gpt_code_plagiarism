TEST(VerifyNameMatchInvalidDataTest, FailOnBmpStringSurrogates) {
  std::string normal;
  ASSERT_TRUE(LoadTestData("unicode_bmp", "BMPSTRING", "unmangled", &normal));
  // Find a known location inside a BMPSTRING in the DER-encoded data.
  size_t replace_location = normal.find("\x67\x71\x4e\xac");
  ASSERT_NE(std::string::npos, replace_location);
  // Replace with U+1D400 MATHEMATICAL BOLD CAPITAL A, which requires surrogates
  // to represent.
  std::string invalid =
      normal.replace(replace_location, 4, std::string("\xd8\x35\xdc\x00", 4));
  // Verification should fail due to the invalid codepoints.
  EXPECT_FALSE(VerifyNameMatch(SequenceValueFromString(&invalid),
                               SequenceValueFromString(&invalid)));
  std::string normalized_der;
  CertErrors errors;
  EXPECT_FALSE(NormalizeName(SequenceValueFromString(&invalid), &normalized_der,
                             &errors));
}