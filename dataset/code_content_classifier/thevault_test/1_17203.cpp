TEST(NameNormalizationTest, NormalizeCustom) {
  std::string raw_der;
  ASSERT_TRUE(LoadTestData("custom", "custom", "normalized", &raw_der));

  std::string normalized_der;
  CertErrors errors;
  ASSERT_TRUE(NormalizeName(SequenceValueFromString(&raw_der), &normalized_der,
                            &errors));
  EXPECT_EQ(SequenceValueFromString(&raw_der), der::Input(&normalized_der));
}