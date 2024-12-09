TEST_F(GAP_LowEnergyConnectionManagerTest, ConnectSinglePeerErrorStatus) {
  auto* peer = peer_cache()->NewPeer(kAddress0, true);
  auto fake_peer = std::make_unique<FakePeer>(kAddress0);
  fake_peer->set_connect_status(hci::StatusCode::kConnectionFailedToBeEstablished);
  test_device()->AddPeer(std::move(fake_peer));

  ASSERT_TRUE(peer->le());
  EXPECT_EQ(Peer::ConnectionState::kNotConnected, peer->le()->connection_state());

  hci::Status status;
  auto callback = [&status](auto cb_status, auto conn_ref) {
    EXPECT_FALSE(conn_ref);
    status = cb_status;
  };

  EXPECT_TRUE(conn_mgr()->Connect(peer->identifier(), callback));
  EXPECT_EQ(Peer::ConnectionState::kInitializing, peer->le()->connection_state());

  RunLoopUntilIdle();

  EXPECT_TRUE(status.is_protocol_error());
  EXPECT_EQ(hci::StatusCode::kConnectionFailedToBeEstablished, status.protocol_error());
  EXPECT_EQ(Peer::ConnectionState::kNotConnected, peer->le()->connection_state());
}