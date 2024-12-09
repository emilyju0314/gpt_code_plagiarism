TEST_F(Bip39EntropyTest, DecodeSuccess) {
  EXPECT_OUTCOME_TRUE(mnemonic, Mnemonic::parse(phrase));
  auto joined_words = boost::algorithm::join(mnemonic.words, " ");
  ASSERT_EQ(joined_words, phrase);

  EXPECT_OUTCOME_TRUE(entropy,
                      bip39_provider->calculateEntropy(mnemonic.words));
  ASSERT_EQ(base::Buffer(entropy).toHex(), entropy_hex);

  EXPECT_OUTCOME_TRUE(seed, bip39_provider->makeSeed(entropy, "Substrate"));
  ASSERT_EQ(seed.toHex(), seed_hex);
}