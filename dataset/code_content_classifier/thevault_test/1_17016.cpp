TEST(InputFileParsersTest, ParseJSON) {
  std::string valid =
      "{"
      "  \"pinsets\": [{"
      "      \"name\": \"test\","
      "      \"static_spki_hashes\": [\"TestSPKI\"],"
      "      \"bad_static_spki_hashes\": [\"BadTestSPKI\"],"
      "      \"report_uri\": \"https://hpkp-log.example.com\""
      "  }],"
      "  \"entries\": ["
      "    {"
      "      \"name\": \"hsts.example.com\","
      "      \"policy\": \"test\","
      "      \"mode\": \"force-https\", "
      "      \"include_subdomains\": true"
      "    }, {"
      "      \"name\": \"hsts-no-subdomains.example.com\","
      "      \"policy\": \"test\","
      "      \"mode\": \"force-https\", "
      "      \"include_subdomains\": false"
      "    }, {"
      "      \"name\": \"hpkp.example.com\","
      "      \"policy\": \"test\","
      "      \"pins\": \"thepinset\","
      "      \"include_subdomains_for_pinning\": true"
      "    }, {"
      "      \"name\": \"hpkp-no-subdomains.example.com\","
      "      \"policy\": \"test\","
      "      \"pins\": \"thepinset2\", "
      "      \"include_subdomains_for_pinning\": false"
      "    }, {"
      "      \"name\": \"expect-ct.example.com\","
      "      \"policy\": \"test\","
      "      \"expect_ct\": true,"
      "      \"expect_ct_report_uri\": \"https://expect-ct-log.example.com\""
      "    }"
      "  ]"
      "}";

  TransportSecurityStateEntries entries;
  Pinsets pinsets;

  EXPECT_TRUE(ParseJSON(valid, &entries, &pinsets));

  ASSERT_EQ(1U, pinsets.size());
  auto pinset = pinsets.pinsets().find("test");
  ASSERT_NE(pinset, pinsets.pinsets().cend());
  EXPECT_EQ("test", pinset->second->name());
  EXPECT_EQ("https://hpkp-log.example.com", pinset->second->report_uri());

  ASSERT_EQ(1U, pinset->second->static_spki_hashes().size());
  EXPECT_EQ("TestSPKI", pinset->second->static_spki_hashes()[0]);

  ASSERT_EQ(1U, pinset->second->bad_static_spki_hashes().size());
  EXPECT_EQ("BadTestSPKI", pinset->second->bad_static_spki_hashes()[0]);

  ASSERT_EQ(5U, entries.size());
  TransportSecurityStateEntry* entry = entries[0].get();
  EXPECT_EQ("hsts.example.com", entry->hostname);
  EXPECT_TRUE(entry->force_https);
  EXPECT_TRUE(entry->include_subdomains);
  EXPECT_FALSE(entry->hpkp_include_subdomains);
  EXPECT_EQ("", entry->pinset);
  EXPECT_FALSE(entry->expect_ct);
  EXPECT_EQ("", entry->expect_ct_report_uri);

  entry = entries[1].get();
  EXPECT_EQ("hsts-no-subdomains.example.com", entry->hostname);
  EXPECT_TRUE(entry->force_https);
  EXPECT_FALSE(entry->include_subdomains);
  EXPECT_FALSE(entry->hpkp_include_subdomains);
  EXPECT_EQ("", entry->pinset);
  EXPECT_FALSE(entry->expect_ct);
  EXPECT_EQ("", entry->expect_ct_report_uri);

  entry = entries[2].get();
  EXPECT_EQ("hpkp.example.com", entry->hostname);
  EXPECT_FALSE(entry->force_https);
  EXPECT_FALSE(entry->include_subdomains);
  EXPECT_TRUE(entry->hpkp_include_subdomains);
  EXPECT_EQ("thepinset", entry->pinset);
  EXPECT_FALSE(entry->expect_ct);
  EXPECT_EQ("", entry->expect_ct_report_uri);

  entry = entries[3].get();
  EXPECT_EQ("hpkp-no-subdomains.example.com", entry->hostname);
  EXPECT_FALSE(entry->force_https);
  EXPECT_FALSE(entry->include_subdomains);
  EXPECT_FALSE(entry->hpkp_include_subdomains);
  EXPECT_EQ("thepinset2", entry->pinset);
  EXPECT_FALSE(entry->expect_ct);
  EXPECT_EQ("", entry->expect_ct_report_uri);

  entry = entries[4].get();
  EXPECT_EQ("expect-ct.example.com", entry->hostname);
  EXPECT_FALSE(entry->force_https);
  EXPECT_FALSE(entry->include_subdomains);
  EXPECT_FALSE(entry->hpkp_include_subdomains);
  EXPECT_EQ("", entry->pinset);
  EXPECT_TRUE(entry->expect_ct);
  EXPECT_EQ("https://expect-ct-log.example.com", entry->expect_ct_report_uri);
}