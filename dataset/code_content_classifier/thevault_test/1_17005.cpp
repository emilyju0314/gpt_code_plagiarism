TEST(RSAPrivateKeyUnitTest, ExtraData) {
  std::vector<uint8_t> input(kTestPrivateKeyInfo,
                             kTestPrivateKeyInfo + sizeof(kTestPrivateKeyInfo));
  input.push_back(0);

  std::unique_ptr<crypto::RSAPrivateKey> key(
      crypto::RSAPrivateKey::CreateFromPrivateKeyInfo(input));

  // Import should fail.
  EXPECT_FALSE(key);
}