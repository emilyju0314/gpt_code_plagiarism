TEST_F(GAP_LowEnergyConnectionManagerTest, L2CAPLEConnectionParameterUpdate) {
  // Set up a fake peer and a connection over which to process the L2CAP
  // request.
  test_device()->AddPeer(std::make_unique<FakePeer>(kAddress0));
  auto* peer = peer_cache()->NewPeer(kAddress0, true);
  ASSERT_TRUE(peer);

  LowEnergyConnectionRefPtr conn_ref;
  auto conn_cb = [&conn_ref](const auto& peer_id, auto cr) { conn_ref = std::move(cr); };
  ASSERT_TRUE(conn_mgr()->Connect(peer->identifier(), conn_cb));

  RunLoopUntilIdle();
  ASSERT_TRUE(conn_ref);

  hci::LEPreferredConnectionParameters preferred(
      hci::kLEConnectionIntervalMin, hci::kLEConnectionIntervalMax, hci::kLEConnectionLatencyMax,
      hci::kLEConnectionSupervisionTimeoutMax);

  hci::LEConnectionParameters actual;
  bool fake_peer_cb_called = false;
  bool conn_params_cb_called = false;

  auto fake_peer_cb = [&actual, &fake_peer_cb_called](const auto& addr, const auto& params) {
    fake_peer_cb_called = true;
    actual = params;
  };
  test_device()->set_le_connection_parameters_callback(fake_peer_cb);

  auto conn_params_cb = [&conn_params_cb_called, &conn_ref](const auto& peer) {
    EXPECT_EQ(conn_ref->peer_identifier(), peer.identifier());
    conn_params_cb_called = true;
  };
  conn_mgr()->SetConnectionParametersCallbackForTesting(conn_params_cb);

  fake_l2cap()->TriggerLEConnectionParameterUpdate(conn_ref->handle(), preferred);

  RunLoopUntilIdle();

  EXPECT_TRUE(fake_peer_cb_called);
  ASSERT_TRUE(conn_params_cb_called);

  ASSERT_TRUE(peer->le());
  EXPECT_EQ(preferred, *peer->le()->preferred_connection_parameters());
  EXPECT_EQ(actual, *peer->le()->connection_parameters());
}