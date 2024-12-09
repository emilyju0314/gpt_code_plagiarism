TEST_F(Secp256k1ProviderTest, RecoverInvalidSignatureFailure) {
  RSVSignature wrong_signature{};
  *wrong_signature.rbegin() = 99;
  EXPECT_OUTCOME_ERROR(res,
                       secp256K1_provider->recoverPublickeyUncompressed(
                           wrong_signature, secp_message_hash),
                       Secp256k1ProviderError::INVALID_ARGUMENT);
}