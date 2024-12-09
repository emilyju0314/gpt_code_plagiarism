TEST_F(SR25519ProviderTest, DISABLED_VerifyInvalidKeyFail) {
  auto kp = sr25519_provider->generateKeypair();
  EXPECT_OUTCOME_TRUE(signature, sr25519_provider->sign(kp, message_span));
  // make public key invalid
  kp.public_key.fill(1);
  EXPECT_OUTCOME_FALSE_1(
      sr25519_provider->verify(signature, message_span, kp.public_key));
}