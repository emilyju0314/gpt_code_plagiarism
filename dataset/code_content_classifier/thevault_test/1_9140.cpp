TEST_F(Secp256k1ProviderTest, RecoverUncompressedSuccess) {
  EXPECT_OUTCOME_TRUE(public_key,
                      secp256K1_provider->recoverPublickeyUncompressed(
                          secp_signature, secp_message_hash));
  EXPECT_EQ(public_key, secp_public_key);
}