TEST(InputFileParsersTest, ParseJSONInvalidPinset) {
  TransportSecurityStateEntries entries;
  Pinsets pinsets;

  std::string missing_pinset_name =
      "{"
      "  \"pinsets\": [{"
      "      \"static_spki_hashes\": [\"TestSPKI\"],"
      "      \"bad_static_spki_hashes\": [\"BadTestSPKI\"],"
      "      \"report_uri\": \"https://hpkp-log.example.com\""
      "  }],"
      "  \"entries\": []"
      "}";

  EXPECT_FALSE(ParseJSON(missing_pinset_name, &entries, &pinsets));
}