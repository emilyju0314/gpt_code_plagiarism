TEST_F(CryptoStoreTest, generateEd25519KeypairStoreSuccess) {
  EXPECT_OUTCOME_TRUE(pair, crypto_store->generateEd25519Keypair(key_type));

  // check that created pair is contained in the storage on disk
  EXPECT_OUTCOME_TRUE(
      found, crypto_store->findEd25519Keypair(key_type, pair.public_key));
  ASSERT_EQ(found, pair);

  // stored on disk
  ASSERT_TRUE(isStoredOnDisk(key_type, pair.public_key));
}