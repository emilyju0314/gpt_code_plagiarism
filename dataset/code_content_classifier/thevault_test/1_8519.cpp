TEST(PBKDF2Test, ScryptRFCSanity0) {
  PBKDF2 PBKDF(EVP_sha256());
  std::vector<std::byte> pbkdf_out_0 =
      PBKDF.hash(utilities::stringToBytes("passwd"),
                 utilities::stringToBytes("salt"), 1, 64);
  std::string expected_pbkdf_out_0 =
      "55 ac 04 6e 56 e3 08 9f ec 16 91 c2 25 44 b6 05 "
      "f9 41 85 21 6d de 04 65 e6 8b 9d 57 c2 0d ac bc "
      "49 ca 9c cc f1 79 b6 45 99 16 64 b3 9d 77 ef 31 "
      "7c 71 b8 45 b1 e3 0b d5 09 11 20 41 d3 a1 97 83 ";
  EXPECT_EQ(pbkdf_out_0, utilities::hexToBytes(expected_pbkdf_out_0));
}