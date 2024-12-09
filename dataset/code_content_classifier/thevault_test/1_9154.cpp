TEST_F(CryptoStoreTest, generateSr25519KeypairMnemonicSuccess) {
  EXPECT_OUTCOME_FALSE(
      err, crypto_store->findSr25519Keypair(key_type, ed_pair.public_key));
  ASSERT_EQ(err, CryptoStoreError::KEY_NOT_FOUND);

  EXPECT_OUTCOME_TRUE(pair,
                      crypto_store->generateSr25519Keypair(key_type, mnemonic));
  ASSERT_EQ(pair, sr_pair);

  // check that created pair is now contained in memory
  EXPECT_OUTCOME_TRUE(
      found, crypto_store->findSr25519Keypair(key_type, pair.public_key));
  ASSERT_EQ(found, pair);
  // not stored on disk
  ASSERT_FALSE(isStoredOnDisk(key_type, pair.public_key));
}