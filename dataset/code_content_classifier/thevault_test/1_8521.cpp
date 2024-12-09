TEST(ScryptTest, RFCSanity1) {
  Scrypt Scrypt;
  std::string expected =
      "fd ba be 1c 9d 34 72 00 78 56 e7 19 0d 01 e9 fe "
      "7c 6a d7 cb c8 23 78 30 e7 73 76 63 4b 37 31 62 "
      "2e af 30 d9 2e 22 a3 88 6f f1 09 27 9d 98 30 da "
      "c7 27 af b9 4a 83 ee 6d 83 60 cb df a2 cc 06 40 ";

  std::vector<std::byte> got =
      Scrypt.hash(utilities::stringToBytes("password"),
                  utilities::stringToBytes("NaCl"), 1024, 8, 16, 64);
  EXPECT_EQ(got, utilities::hexToBytes(expected));
}