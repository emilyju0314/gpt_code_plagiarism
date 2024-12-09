TEST_F(SMP_BearerTest, FeatureExchangePairingResponseMITM) {
  NewBearer(hci::Connection::Role::kMaster, hci::Connection::LinkType::kLE,
            false /* sc_supported */, true /* bondable_mode */, IOCapability::kDisplayYesNo);

  // clang-format off
  const auto kRequest = CreateStaticByteBuffer(
      0x01,  // code: Pairing Request
      0x01,  // IO cap.: DisplayYesNo
      0x00,  // OOB: not present
      0x01,  // AuthReq: bonding, MITM not required
      0x10,  // encr. key size: 16 (default max)
      0x00,  // initiator keys: none
      0x03   // responder keys: enc key and identity info
  );
  const auto kResponse = CreateStaticByteBuffer(
      0x02,  // code: Pairing Response
      0x02,  // IO cap.: KeyboardOnly
      0x00,  // OOB: not present
      0x05,  // AuthReq: MITM required, bondable mode
      0x07,  // encr. key size: 7 (default min)
      0x00,  // initiator keys: none
      0x01   // responder keys: enc key only
  );
  // clang-format on

  // Initiate the request in a loop task for Expect to detect it.
  async::PostTask(dispatcher(), [this] { bearer()->InitiateFeatureExchange(); });
  ASSERT_TRUE(Expect(kRequest));
  ASSERT_TRUE(bearer()->pairing_started());

  fake_chan()->Receive(kResponse);
  RunLoopUntilIdle();

  // Pairing should continue until explicitly stopped.
  EXPECT_TRUE(bearer()->pairing_started());
  EXPECT_EQ(0, pairing_error_count());
  EXPECT_EQ(1, feature_exchange_count());

  EXPECT_TRUE(features().initiator);
  EXPECT_FALSE(features().secure_connections);
  EXPECT_EQ(PairingMethod::kPasskeyEntryDisplay, features().method);
  EXPECT_EQ(7, features().encryption_key_size);
  EXPECT_FALSE(features().local_key_distribution);
  EXPECT_TRUE(KeyDistGen::kEncKey & features().remote_key_distribution);
  EXPECT_TRUE(ContainersEqual(kRequest, preq()));
  EXPECT_TRUE(ContainersEqual(kResponse, pres()));
}