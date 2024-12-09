TEST(InputFileParsersTest, ParseJSONInvalid) {
  TransportSecurityStateEntries entries;
  Pinsets pinsets;

  std::string no_pinsets =
      "{"
      "  \"entries\": []"
      "}";

  EXPECT_FALSE(ParseJSON(no_pinsets, &entries, &pinsets));

  std::string no_entries =
      "{"
      "  \"pinsets\": []"
      "}";

  EXPECT_FALSE(ParseJSON(no_entries, &entries, &pinsets));

  std::string missing_hostname =
      "{"
      "  \"pinsets\": [],"
      "  \"entries\": ["
      "    {"
      "      \"policy\": \"test\","
      "      \"mode\": \"force-https\""
      "    }"
      "  ]"
      "}";

  EXPECT_FALSE(ParseJSON(missing_hostname, &entries, &pinsets));

  std::string missing_policy =
      "{"
      "  \"pinsets\": [],"
      "  \"entries\": ["
      "    {"
      "      \"name\": \"example.test\","
      "      \"mode\": \"force-https\""
      "    }"
      "  ]"
      "}";

  EXPECT_FALSE(ParseJSON(missing_policy, &entries, &pinsets));
}