TEST_F(SR25519ProviderTest, GenerateBySeedSuccess) {
  EXPECT_OUTCOME_TRUE(seed, SR25519Seed::fromHex(hex_seed));
  EXPECT_OUTCOME_TRUE(public_key, SR25519PublicKey::fromHex(hex_vk));

  // private key is the same as seed
  EXPECT_OUTCOME_TRUE(secret_key, SR25519SecretKey::fromHex(hex_sk));

  auto &&kp = sr25519_provider->generateKeypair(seed);

  ASSERT_EQ(kp.secret_key.toHex(), secret_key.toHex());
  ASSERT_EQ(kp.public_key.toHex(), public_key.toHex());
}