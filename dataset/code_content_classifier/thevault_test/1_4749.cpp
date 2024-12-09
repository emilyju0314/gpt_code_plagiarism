TEST(AesSivBoringSslTest, testEncryptDecryptAadSize) {
  std::string key(test::HexDecodeOrDie(
      "000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f"
      "00112233445566778899aabbccddeefff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff"));
  auto res = AesSivBoringSsl::New(key);
  EXPECT_TRUE(res.ok()) << res.status();
  auto cipher = std::move(res.ValueOrDie());
  std::string message = "Some plaintext";
  for (int i = 0; i < 1028; ++i) {
    std::string aad = std::string(i, 'a');
    auto ct = cipher->EncryptDeterministically(message, aad);
    EXPECT_TRUE(ct.ok()) << ct.status();
    auto pt = cipher->DecryptDeterministically(ct.ValueOrDie(), aad);
    EXPECT_TRUE(pt.ok()) << pt.status();
    EXPECT_EQ(pt.ValueOrDie(), message);
  }
}