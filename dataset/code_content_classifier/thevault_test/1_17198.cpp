TEST(VerifyNameMatchInvalidDataTest, FailOnInvalidIA5StringChars) {
  std::string der;
  ASSERT_TRUE(LoadTestData("ascii", "mixed", "rdn_dupetype_sorting_1", &der));
  // Find a known location inside an IA5String in the DER-encoded data.
  size_t replace_location = der.find("eXaMple");
  ASSERT_NE(std::string::npos, replace_location);
  for (int c = 0; c < 256; ++c) {
    SCOPED_TRACE(base::NumberToString(c));
    der.replace(replace_location, 1, 1, c);
    bool expected_result = (c <= 127);
    EXPECT_EQ(expected_result, VerifyNameMatch(SequenceValueFromString(&der),
                                               SequenceValueFromString(&der)));
    std::string normalized_der;
    CertErrors errors;
    EXPECT_EQ(expected_result, NormalizeName(SequenceValueFromString(&der),
                                             &normalized_der, &errors));
  }
}