TEST(InputFileParsersTest, ParseCertificatesFile) {
  std::string valid =
      "# This line should ignored. The rest should result in 3 pins.\n"
      "TestPublicKey1\n"
      "sha256/AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA=\n"
      "\n"
      "TestPublicKey2\n"
      "-----BEGIN PUBLIC KEY-----\n"
      "MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAujzwcb5bJuC/A/Y9izGl\n"
      "LlA3fnKGbeyn53BdVznJN4fQwU82WKVYdqt8d/1ZDRdYyhGrTgXJeCURe9VSJyX1\n"
      "X2a5EApSFsopP8Yjy0Rl6dNOLO84KCW9dPmfHC3uP0ac4hnHT5dUr05YvhJmHCkf\n"
      "as6v/aEgpPLDhRF6UruSUh+gIpUg/F3+vlD99HLfbloukoDtQyxW+86s9sO7RQ00\n"
      "pd79VOoa/v09FvoS7MFgnBBOtvBQLOXjEH7/qBsnrXFtHBeOtxSLar/FL3OhVXuh\n"
      "dUTRyc1Mg0ECtz8zHZugW+LleIm5Bf5Yr0bN1O/HfDPCkDaCldcm6xohEHn9pBaW\n"
      "+wIDAQAB\n"
      "-----END PUBLIC KEY-----\n"
      "\n"
      "# The 'Chromium' prefix is required here.\n"
      "ChromiumTestCertificate3\n"
      "-----BEGIN CERTIFICATE-----\n"
      "MIIDeTCCAmGgAwIBAgIJAMRHXuiAgufAMA0GCSqGSIb3DQEBCwUAMFMxETAPBgNV\n"
      "BAMMCENocm9taXVtMR4wHAYDVQQKDBVUaGUgQ2hyb21pdW0gUHJvamVjdHMxETAP\n"
      "BgNVBAsMCFNlY3VyaXR5MQswCQYDVQQGEwJVUzAeFw0xNzAyMDExOTAyMzFaFw0x\n"
      "ODAyMDExOTAyMzFaMFMxETAPBgNVBAMMCENocm9taXVtMR4wHAYDVQQKDBVUaGUg\n"
      "Q2hyb21pdW0gUHJvamVjdHMxETAPBgNVBAsMCFNlY3VyaXR5MQswCQYDVQQGEwJV\n"
      "UzCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALtggpf5vNVsmQrJKTQe\n"
      "ynTeOzVOyROGDugGtR+Cri8WlNg1UAlIyYIS8txZ4oCknsT8gs3TFfu0wxmWNxx5\n"
      "4oLGy2BQOHH00dgBAsKgqX//mY4mH5AZ85UFYni1hj9aszIJMIBWtgbNGVkppW65\n"
      "8maF1KVdHmxXMvtKxn/9UsusH/A0ng5UJDYBPISQMv0XqIlv0wdVTIVWIcQhOjWz\n"
      "MGwFDSjxS1WgEnPgd4Qi7MYaDbUTsXGtWba83vZJ8CQzjLumSJJCnz2aquGmraX0\n"
      "J0joUjB4fuYL8xrbDqnFmADvozMMVkZ4843w8ikvJkM8nWoIXexVvirfXDoqtdUo\n"
      "YOcCAwEAAaNQME4wHQYDVR0OBBYEFGJ6O/oLtzpb4OWvrEFxieYb1JbsMB8GA1Ud\n"
      "IwQYMBaAFGJ6O/oLtzpb4OWvrEFxieYb1JbsMAwGA1UdEwQFMAMBAf8wDQYJKoZI\n"
      "hvcNAQELBQADggEBAFpt9jlBT6OsfKFAJZnmExbW8JlsqXOJAaR+nD1XOnp6o+DM\n"
      "NIguj9+wJOW34OM+2Om0n+KMYbDER0p4g3gxoaDblu7otgnC0OTOnx3DPUYab0jr\n"
      "uT6O4C3/nfWW5sl3Ni3Y99dmdcqKcmYkHsr7uADLPWsjb+sfUrQQfHHnPwzyUz/A\n"
      "w4rSJ0wxnLOmjk5F5YHMLkNpPrzFA1mFyGIau7THsRIr3B632MLNcOlNR21nOc7i\n"
      "eB4u+OzpcZXuiQg3bqrNp6Xb70OIW1rfNEiCpps4UZyRnZ/nrzByxeHH5zPWWZk9\n"
      "nZtxI+65PFOekOjBpbnRC8v1CfOmUSVKIqWaPys=\n"
      "-----END CERTIFICATE-----";

  Pinsets pinsets;
  EXPECT_TRUE(ParseCertificatesFile(valid, &pinsets));
  EXPECT_EQ(3U, pinsets.spki_size());

  const SPKIHashMap& hashes = pinsets.spki_hashes();
  EXPECT_NE(hashes.cend(), hashes.find("TestPublicKey1"));
  EXPECT_NE(hashes.cend(), hashes.find("TestPublicKey2"));
  EXPECT_NE(hashes.cend(), hashes.find("ChromiumTestCertificate3"));
}