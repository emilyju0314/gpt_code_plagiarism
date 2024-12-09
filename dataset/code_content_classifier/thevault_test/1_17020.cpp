TEST(InputFileParsersTest, ParseJSONUnkownField) {
  TransportSecurityStateEntries entries;
  Pinsets pinsets;

  std::string unknown_field =
      "{"
      "  \"pinsets\": [],"
      "  \"entries\": ["
      "    {"
      "      \"name\": \"preloaded.test\","
      "      \"policy\": \"test\","
      "      \"unknown_key\": \"value\""
      "    }"
      "  ]"
      "}";

  EXPECT_FALSE(ParseJSON(unknown_field, &entries, &pinsets));
}