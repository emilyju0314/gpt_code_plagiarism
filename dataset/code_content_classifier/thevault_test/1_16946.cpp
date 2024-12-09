void RunTestCase(VerifyResult expected_result, const char* file_name) {
  std::string path =
      std::string("net/data/verify_signed_data_unittest/") + file_name;

  std::string public_key;
  std::string algorithm;
  std::string signed_data;
  std::string signature_value;

  const PemBlockMapping mappings[] = {
      {"PUBLIC KEY", &public_key},
      {"ALGORITHM", &algorithm},
      {"DATA", &signed_data},
      {"SIGNATURE", &signature_value},
  };

  ASSERT_TRUE(ReadTestDataFromPemFile(path, mappings));

  CertErrors algorithm_errors;
  std::unique_ptr<SignatureAlgorithm> signature_algorithm =
      SignatureAlgorithm::Create(der::Input(&algorithm), &algorithm_errors);
  ASSERT_TRUE(signature_algorithm) << algorithm_errors.ToDebugString();

  der::BitString signature_value_bit_string;
  der::Parser signature_value_parser((der::Input(&signature_value)));
  ASSERT_TRUE(signature_value_parser.ReadBitString(&signature_value_bit_string))
      << "The signature value is not a valid BIT STRING";

  bool expected_result_bool = expected_result == SUCCESS;

  bool result =
      VerifySignedData(*signature_algorithm, der::Input(&signed_data),
                       signature_value_bit_string, der::Input(&public_key));

  EXPECT_EQ(expected_result_bool, result);
}