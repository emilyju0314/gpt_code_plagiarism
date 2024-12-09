TEST(InputFileParsersTest, ParseJSONUnkownPolicy) {
  TransportSecurityStateEntries entries;
  Pinsets pinsets;

  std::string unknown_policy =
      "{"
      "  \"pinsets\": [],"
      "  \"entries\": ["
      "    {"
      "      \"name\": \"preloaded.test\","
      "      \"policy\": \"invalid\""
      "    }"
      "  ]"
      "}";

  EXPECT_FALSE(ParseJSON(unknown_policy, &entries, &pinsets));
}