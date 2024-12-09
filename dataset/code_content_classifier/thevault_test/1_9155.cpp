TEST_F(CryptoStoreTest, generateEd25519KeypairSeedSuccess) {
  EXPECT_OUTCOME_FALSE(
      err, crypto_store->findEd25519Keypair(key_type, ed_pair.public_key));
  ASSERT_EQ(err, CryptoStoreError::KEY_NOT_FOUND);

  auto &&pair = crypto_store->generateEd25519Keypair(key_type, seed);
  ASSERT_EQ(pair, ed_pair);

  // check that created pair is now contained in memory
  EXPECT_OUTCOME_TRUE(
      found, crypto_store->findEd25519Keypair(key_type, pair.public_key));
  ASSERT_EQ(found, pair);
  // not stored on disk
  ASSERT_FALSE(isStoredOnDisk(key_type, pair.public_key));
}