void RunCertificateTest(const std::string& file_name) {
  std::string data;
  std::string expected_errors;
  std::string expected_tbs_certificate;
  std::string expected_signature_algorithm;
  std::string expected_signature;

  // Read the certificate data and test expectations from a single PEM file.
  const PemBlockMapping mappings[] = {
      {"CERTIFICATE", &data},
      {"ERRORS", &expected_errors, true /*optional*/},
      {"SIGNATURE", &expected_signature, true /*optional*/},
      {"SIGNATURE ALGORITHM", &expected_signature_algorithm, true /*optional*/},
      {"TBS CERTIFICATE", &expected_tbs_certificate, true /*optional*/},
  };
  std::string test_file_path = GetFilePath(file_name);
  ASSERT_TRUE(ReadTestDataFromPemFile(test_file_path, mappings));

  // Note that empty expected_errors doesn't necessarily mean success.
  bool expected_result = !expected_tbs_certificate.empty();

  // Parsing the certificate.
  der::Input tbs_certificate_tlv;
  der::Input signature_algorithm_tlv;
  der::BitString signature_value;
  CertErrors errors;
  bool actual_result =
      ParseCertificate(der::Input(&data), &tbs_certificate_tlv,
                       &signature_algorithm_tlv, &signature_value, &errors);

  EXPECT_EQ(expected_result, actual_result);
  VerifyCertErrors(expected_errors, errors, test_file_path);

  // Ensure that the parsed certificate matches expectations.
  if (expected_result && actual_result) {
    EXPECT_EQ(0, signature_value.unused_bits());
    EXPECT_EQ(der::Input(&expected_signature), signature_value.bytes());
    EXPECT_EQ(der::Input(&expected_signature_algorithm),
              signature_algorithm_tlv);
    EXPECT_EQ(der::Input(&expected_tbs_certificate), tbs_certificate_tlv);
  }
}