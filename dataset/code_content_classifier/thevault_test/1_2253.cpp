TEST_F(SMP_BearerTest, FeatureExchangeResponderDistributesIdKey) {
  // clang-format off
  const auto kRequest = CreateStaticByteBuffer(
      0x01,  // code: Pairing Request
      0x03,  // IO cap.: NoInputNoOutput
      0x00,  // OOB: not present
      0x01,  // AuthReq: bondable mode
      0x10,  // encr. key size: 16 (default max)
      0x00,  // initiator keys: none
      0x02   // responder keys: identity info
  );
  const auto kResponse = CreateStaticByteBuffer(
      0x02,  // code: Pairing Response
      0x03,  // IO cap.: NoInputNoOutput
      0x00,  // OOB: not present
      0x01,  // AuthReq: bonding, no MITM
      0x10,  // encr. key size: 16 (default max)
      0x00,  // initiator keys: none
      0x02   // responder keys: identity info
  );
  // clang-format on

  NewBearer(hci::Connection::Role::kSlave);
  set_has_identity_info(true);

  EXPECT_TRUE(ReceiveAndExpect(kRequest, kResponse));
  EXPECT_TRUE(bearer()->pairing_started());
  EXPECT_EQ(1, feature_exchange_count());
  EXPECT_FALSE(features().initiator);
  EXPECT_TRUE(features().local_key_distribution & KeyDistGen::kIdKey);
  EXPECT_FALSE(features().remote_key_distribution);
}