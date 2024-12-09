TEST_F(SMP_BearerTest, FeatureExchangeResponderTimerRestarted) {
  NewBearer(hci::Connection::Role::kSlave);

  constexpr auto kThresholdSeconds = zx::sec(1);
  const auto kRequest = CreateStaticByteBuffer(0x01,  // code: Pairing Request
                                               0x03,  // IO cap.: NoInputNoOutput
                                               0x00,  // OOB: not present
                                               0x00,  // AuthReq: no auth. request by default
                                               0x10,  // encr. key size: 16 (default max)
                                               0x00,  // initiator key dist.: encr. key only
                                               0x00   // responder key dist.: encr. key only
  );
  fake_chan()->Receive(kRequest);
  RunLoopUntilIdle();
  ASSERT_TRUE(bearer()->pairing_started());

  // Advance the time to 1 second behind the end of the pairing timeout.
  RunLoopFor(kPairingTimeout - kThresholdSeconds);

  // The timer should not have expired.
  EXPECT_TRUE(bearer()->pairing_started());
  EXPECT_FALSE(fake_chan()->link_error());
  EXPECT_EQ(0, pairing_error_count());
  EXPECT_TRUE(last_error().is_success());

  // Send a second request which should restart the timer.
  fake_chan()->Receive(kRequest);
  RunLoopUntilIdle();
  EXPECT_TRUE(bearer()->pairing_started());

  // The old timeout should not expire when advance to 1 second behind the new
  // timeout.
  RunLoopFor(kPairingTimeout - kThresholdSeconds);
  EXPECT_TRUE(bearer()->pairing_started());
  EXPECT_EQ(0, pairing_error_count());

  RunLoopFor(kThresholdSeconds);
  EXPECT_FALSE(bearer()->pairing_started());
  EXPECT_EQ(1, pairing_error_count());
  EXPECT_EQ(HostError::kTimedOut, last_error().error());
}