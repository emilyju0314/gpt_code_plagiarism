TEST(RSAPrivateKeyUnitTest, InitRandomTest) {
  std::unique_ptr<crypto::RSAPrivateKey> keypair1(
      crypto::RSAPrivateKey::Create(1024));
  std::unique_ptr<crypto::RSAPrivateKey> keypair2(
      crypto::RSAPrivateKey::Create(2048));
  ASSERT_TRUE(keypair1.get());
  ASSERT_TRUE(keypair2.get());

  std::vector<uint8_t> privkey1;
  std::vector<uint8_t> privkey2;
  std::vector<uint8_t> pubkey1;
  std::vector<uint8_t> pubkey2;

  ASSERT_TRUE(keypair1->ExportPrivateKey(&privkey1));
  ASSERT_TRUE(keypair2->ExportPrivateKey(&privkey2));
  ASSERT_TRUE(keypair1->ExportPublicKey(&pubkey1));
  ASSERT_TRUE(keypair2->ExportPublicKey(&pubkey2));

  std::unique_ptr<crypto::RSAPrivateKey> keypair3(
      crypto::RSAPrivateKey::CreateFromPrivateKeyInfo(privkey1));
  std::unique_ptr<crypto::RSAPrivateKey> keypair4(
      crypto::RSAPrivateKey::CreateFromPrivateKeyInfo(privkey2));
  ASSERT_TRUE(keypair3.get());
  ASSERT_TRUE(keypair4.get());

  std::vector<uint8_t> privkey3;
  std::vector<uint8_t> privkey4;
  ASSERT_TRUE(keypair3->ExportPrivateKey(&privkey3));
  ASSERT_TRUE(keypair4->ExportPrivateKey(&privkey4));

  ASSERT_EQ(privkey1.size(), privkey3.size());
  ASSERT_EQ(privkey2.size(), privkey4.size());
  ASSERT_EQ(0, memcmp(&privkey1.front(), &privkey3.front(), privkey1.size()));
  ASSERT_EQ(0, memcmp(&privkey2.front(), &privkey4.front(), privkey2.size()));
}