TEST_F(GAP_LowEnergyConnectionManagerTest, IncomingConnectionUpgradesKnownBrEdrPeerToDualMode) {
  Peer* peer = peer_cache()->NewPeer(kAddrAlias0, true);
  ASSERT_TRUE(peer);
  ASSERT_EQ(peer, peer_cache()->FindByAddress(kAddress0));
  ASSERT_EQ(TechnologyType::kClassic, peer->technology());

  test_device()->AddPeer(std::make_unique<FakePeer>(kAddress0));

  // First create a fake incoming connection.
  test_device()->ConnectLowEnergy(kAddress0);

  RunLoopUntilIdle();

  auto link = MoveLastRemoteInitiated();
  ASSERT_TRUE(link);

  LowEnergyConnectionRefPtr conn_ref = conn_mgr()->RegisterRemoteInitiatedLink(std::move(link));
  ASSERT_TRUE(conn_ref);

  EXPECT_EQ(peer->identifier(), conn_ref->peer_identifier());
  EXPECT_EQ(TechnologyType::kDualMode, peer->technology());
}