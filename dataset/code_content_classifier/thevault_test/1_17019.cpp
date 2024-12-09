TEST(InputFileParsersTest, ParseJSONInvalidMode) {
  TransportSecurityStateEntries entries;
  Pinsets pinsets;

  std::string invalid_mode =
      "{"
      "  \"pinsets\": [],"
      "  \"entries\": ["
      "    {"
      "      \"name\": \"preloaded.test\","
      "      \"policy\": \"test\","
      "      \"mode\": \"something-invalid\""
      "    }"
      "  ]"
      "}";

  EXPECT_FALSE(ParseJSON(invalid_mode, &entries, &pinsets));
}