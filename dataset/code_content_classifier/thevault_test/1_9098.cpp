TEST_F(SR25519ProviderTest, DISABLED_SignWithInvalidKeyFails) {
  auto kp = sr25519_provider->generateKeypair();
  kp.public_key.fill(1);
  EXPECT_OUTCOME_FALSE_1(sr25519_provider->sign(kp, message_span));
}