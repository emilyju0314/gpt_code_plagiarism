TEST_F(GAP_LowEnergyConnectionManagerTest, PeerDoesNotExpireDuringTimeout) {
  // Set a connection timeout that is longer than the PeerCache expiry
  // timeout.
  // TODO(BT-825): Consider configuring the cache timeout explicitly rather than
  // relying on the kCacheTimeout constant.
  constexpr zx::duration kTestRequestTimeout = kCacheTimeout + zx::sec(1);
  conn_mgr()->set_request_timeout_for_testing(kTestRequestTimeout);

  // Note: Use a random address so that the peer becomes temporary upon failure.
  auto* peer = peer_cache()->NewPeer(kAddress1, true);
  EXPECT_TRUE(peer->temporary());

  hci::Status status;
  auto callback = [&status](auto cb_status, auto conn_ref) {
    EXPECT_FALSE(conn_ref);
    status = cb_status;
  };
  EXPECT_TRUE(conn_mgr()->Connect(peer->identifier(), callback));
  ASSERT_TRUE(peer->le());
  EXPECT_EQ(Peer::ConnectionState::kInitializing, peer->le()->connection_state());
  EXPECT_FALSE(peer->temporary());

  RunLoopFor(kTestRequestTimeout);
  EXPECT_EQ(HostError::kTimedOut, status.error()) << status.ToString();
  EXPECT_EQ(peer, peer_cache()->FindByAddress(kAddress1));
  EXPECT_EQ(Peer::ConnectionState::kNotConnected, peer->le()->connection_state());
  EXPECT_TRUE(peer->temporary());
}