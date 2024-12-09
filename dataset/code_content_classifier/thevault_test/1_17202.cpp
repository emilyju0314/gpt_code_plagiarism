TEST(NameNormalizationTest, TestEverything) {
  std::string expected_normalized_der;
  ASSERT_TRUE(
      LoadTestData("unicode", "mixed", "normalized", &expected_normalized_der));

  std::string raw_der;
  ASSERT_TRUE(LoadTestData("unicode", "mixed", "unnormalized", &raw_der));
  std::string normalized_der;
  CertErrors errors;
  ASSERT_TRUE(NormalizeName(SequenceValueFromString(&raw_der), &normalized_der,
                            &errors));
  EXPECT_EQ(SequenceValueFromString(&expected_normalized_der),
            der::Input(&normalized_der));
  // Re-normalizing an already normalized Name should not change it.
  std::string renormalized_der;
  ASSERT_TRUE(
      NormalizeName(der::Input(&normalized_der), &renormalized_der, &errors));
  EXPECT_EQ(normalized_der, renormalized_der);
}