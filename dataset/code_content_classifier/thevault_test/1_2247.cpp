TEST_F(GAP_LowEnergyConnectionManagerTest, RegisterRemoteInitiatedLink) {
  test_device()->AddPeer(std::make_unique<FakePeer>(kAddress0));

  // First create a fake incoming connection.
  test_device()->ConnectLowEnergy(kAddress0);

  RunLoopUntilIdle();

  auto link = MoveLastRemoteInitiated();
  ASSERT_TRUE(link);

  LowEnergyConnectionRefPtr conn_ref = conn_mgr()->RegisterRemoteInitiatedLink(std::move(link));
  ASSERT_TRUE(conn_ref);
  EXPECT_TRUE(conn_ref->active());

  // A Peer should now exist in the cache.
  auto* peer = peer_cache()->FindByAddress(kAddress0);
  ASSERT_TRUE(peer);
  EXPECT_EQ(peer->identifier(), conn_ref->peer_identifier());
  EXPECT_TRUE(peer->connected());
  EXPECT_TRUE(peer->le()->connected());

  conn_ref = nullptr;

  RunLoopUntilIdle();
  EXPECT_TRUE(connected_peers().empty());
}