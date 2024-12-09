TEST(InputFileParsersTest, ParseCertificatesFileInvalidCertificateName) {
  Pinsets pinsets;
  std::string certificate =
      "-----BEGIN CERTIFICATE-----\n"
      "MIIDIzCCAgugAwIBAgIJALs84KlxWh4GMA0GCSqGSIb3DQEBCwUAMCgxGTAXBgNV\n"
      "BAoMEENocm9taXVtIENsYXNzIDMxCzAJBgNVBAsMAkcxMB4XDTE3MDIwMTE5NTUw\n"
      "NVoXDTE4MDIwMTE5NTUwNVowKDEZMBcGA1UECgwQQ2hyb21pdW0gQ2xhc3MgMzEL\n"
      "MAkGA1UECwwCRzEwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQDkolrR\n"
      "7gCPm22Cc9psS2Jh1mksVneee5ntEezZ2gEU20y9Z9URBReo8SFvaZcgKkAkca1v\n"
      "552YIG+FBO/u8njxzlHXvuVJ5x2geciqqR4TRhA4jO1ndrNW6nlJfOoYueWbdym3\n"
      "8zwugoULoCtyLyzdiMI5g8iVBQHDh8+K3TZIHar3HS49TjX5u5nv4igO4RfDcFUa\n"
      "h8g+6x5nWoFF8oa3FG0YTN+q6iI1i2JHmj/q03fVPv3WLPGJ3JADau9gO1Lw1/qf\n"
      "R/N3l4MVtjDFFGYzclfqW2UmL6zRirEV0GF2gwSBAGVX3WWhpOcM8rFIWYkZCsI5\n"
      "iUdtwFNBfcKS9sNpAgMBAAGjUDBOMB0GA1UdDgQWBBTm4VJfibducqwb9h4XELn3\n"
      "p6zLVzAfBgNVHSMEGDAWgBTm4VJfibducqwb9h4XELn3p6zLVzAMBgNVHRMEBTAD\n"
      "AQH/MA0GCSqGSIb3DQEBCwUAA4IBAQApTm40RfsZG20IIgWJ62pZ2end/lvaneTh\n"
      "MZSgFnoTRjKkd/5dh22YyKPw9PnpIuiyi85L36COreqZUvbxqRQnpL1oSCRlLBJQ\n"
      "2LcGlF0j0Opa+SY2VWup4XjnYF8CvwMl4obNpSuywTFmkXCRxzN23tn8whNHvWHM\n"
      "BQ7abw8X1KY02uPbHucrpou6KXkKkhyhfML8OD8IRkSM56K6YyedqV97cmEdW0Ie\n"
      "LlpFJQVX13bmojtSNI1zaiCiEenn5xLa/dAlyFT18Mq6y8plioBinVWFYd0qcRoA\n"
      "E2j3m+jTVIv3CZ+ivGxggZQ8ZYN8FJ/iTW3pXGojogHh0NRJJ8dM\n"
      "-----END CERTIFICATE-----";

  std::string missing_prefix = "Class3_G1_Test\n" + certificate;
  EXPECT_FALSE(ParseCertificatesFile(missing_prefix, &pinsets));

  std::string missing_class = "Chromium_G1_Test\n" + certificate;
  EXPECT_FALSE(ParseCertificatesFile(missing_class, &pinsets));

  std::string missing_number = "Chromium_Class3_Test\n" + certificate;
  EXPECT_FALSE(ParseCertificatesFile(missing_number, &pinsets));

  std::string valid = "Chromium_Class3_G1_Test\n" + certificate;
  EXPECT_TRUE(ParseCertificatesFile(valid, &pinsets));
}