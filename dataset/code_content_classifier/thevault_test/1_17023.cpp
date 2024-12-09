TEST(InputFileParsersTest, ParseCertificatesFileInvalidName) {
  Pinsets pinsets;

  std::string invalid_name_small_character =
      "startsWithSmallLetter\n"
      "sha256/AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA=\n";
  EXPECT_FALSE(ParseCertificatesFile(invalid_name_small_character, &pinsets));

  std::string invalid_name_invalid_characters =
      "Invalid-Characters-In-Name\n"
      "sha256/AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA=\n";
  EXPECT_FALSE(
      ParseCertificatesFile(invalid_name_invalid_characters, &pinsets));

  std::string invalid_name_number =
      "1InvalidName\n"
      "sha256/AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA=\n";
  EXPECT_FALSE(ParseCertificatesFile(invalid_name_number, &pinsets));

  std::string invalid_name_space =
      "Invalid Name\n"
      "sha256/AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA=\n";
  EXPECT_FALSE(ParseCertificatesFile(invalid_name_space, &pinsets));
}