TEST_F(SMP_BearerTest, FeatureExchangeLocalResponderRespectsInitiator) {
  // clang-format off
  const auto kRequest = CreateStaticByteBuffer(
      0x01,  // code: Pairing Request
      0x03,  // IO cap.: NoInputNoOutput
      0x00,  // OOB: not present
      0x01,  // AuthReq: bondable, no MITM
      0x10,  // encr. key size: 16 (default max)
      0x01,  // initiator key dist.: encr. key only
      0x00   // responder key dist.: none
  );
  const auto kResponse = CreateStaticByteBuffer(
      0x02,  // code: Pairing Response
      0x03,  // IO cap.: NoInputNoOutput
      0x00,  // OOB: not present
      0x01,  // AuthReq: bonding, no MITM
      0x10,  // encr. key size: 16 (default max)
      0x00,  // initiator keys: none  // We shouldn't request the IdKey
      0x00   // responder keys: none
  );
  // clang-format on

  NewBearer(hci::Connection::Role::kSlave);
  EXPECT_TRUE(ReceiveAndExpect(kRequest, kResponse));
  EXPECT_TRUE(bearer()->pairing_started());
  EXPECT_EQ(1, feature_exchange_count());
  EXPECT_FALSE(features().initiator);
  EXPECT_FALSE(features().local_key_distribution);
  EXPECT_FALSE(features().remote_key_distribution);
}