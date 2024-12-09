TEST_F(CryptoStoreTest, getEd25519PublicKeysSuccess) {
  EXPECT_OUTCOME_TRUE(pair1, crypto_store->generateEd25519Keypair(kProd));
  EXPECT_OUTCOME_TRUE(pair2, crypto_store->generateEd25519Keypair(kProd));
  EXPECT_OUTCOME_SUCCESS(pair3, crypto_store->generateEd25519Keypair(kLp2p));
  EXPECT_OUTCOME_SUCCESS(pair4, crypto_store->generateSr25519Keypair(kProd));
  EXPECT_OUTCOME_SUCCESS(pair5, crypto_store->generateSr25519Keypair(kAcco));

  std::set<ED25519PublicKey> ed_production_keys_set = {pair1.public_key,
                                                 pair2.public_key};
  std::vector<ED25519PublicKey> ed_production_keys(ed_production_keys_set.begin(),
                                             ed_production_keys_set.end());

  auto &&keys = crypto_store->getEd25519PublicKeys(kProd);
  ASSERT_EQ(ed_production_keys, keys);
}