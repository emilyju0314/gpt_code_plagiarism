TEST(ScryptTest, RFCSanity0) {
  Scrypt Scrypt;
  std::string expected =
      "77 d6 57 62 38 65 7b 20 3b 19 ca 42 c1 8a 04 97 "
      "f1 6b 48 44 e3 07 4a e8 df df fa 3f ed e2 14 42 "
      "fc d0 06 9d ed 09 48 f8 32 6a 75 3a 0f c8 1f 17 "
      "e8 d3 e0 fb 2e 0d 36 28 cf 35 e2 0c 38 d1 89 06 ";

  std::vector<std::byte> got = Scrypt.hash(
      utilities::stringToBytes(""), utilities::stringToBytes(""), 16, 1, 1, 64);
  EXPECT_EQ(got, utilities::hexToBytes(expected));
}