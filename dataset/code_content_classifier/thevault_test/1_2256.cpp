TEST_F(SMP_BearerTest, FeatureExchangeInitiatorReqBondResNoBond) {
  // clang-format off
  const auto kRequest = CreateStaticByteBuffer(
      0x01,  // code: Pairing Request
      0x03,  // IO cap.: NoInputNoOutput
      0x00,  // OOB: not present
      0x01,  // AuthReq: bonding, MITM not required
      0x10,  // encr. key size: 16 (default max)
      0x00,  // initiator keys: none
      0x03   // responder keys: enc key and identity info
  );
  const auto kResponse = CreateStaticByteBuffer(
      0x02,  // code: Pairing Response
      0x00,  // IO cap.: DisplayOnly
      0x00,  // OOB: not present
      0x00,  // AuthReq: no bonding, MITM not required
      0x07,  // encr. key size: 7 (default min)
      0x00,  // initiator keys: none
      0x00   // responder keys: none due to non-bondable mode
  );
  // clang-format on

  // Initiate the request in a loop task for Expect to detect it.
  async::PostTask(dispatcher(), [this] { bearer()->InitiateFeatureExchange(); });
  ASSERT_TRUE(Expect(kRequest));
  ASSERT_TRUE(bearer()->pairing_started());

  fake_chan()->Receive(kResponse);
  RunLoopUntilIdle();

  // Should be in non-bondable mode even though the Initiator specifies bonding, as kResponse
  // indicated that the peer follower does not support bonding.
  EXPECT_EQ(features().bondable_mode, false);
  EXPECT_EQ(features().local_key_distribution, 0u);
  EXPECT_EQ(features().remote_key_distribution, 0u);
}