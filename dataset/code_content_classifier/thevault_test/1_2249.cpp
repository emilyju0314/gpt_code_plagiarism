TEST_F(GAP_LowEnergyConnectionManagerTest, ConnectAndDisconnectDualModeDeviceWithBrEdrAddress) {
  Peer* peer = peer_cache()->NewPeer(kAddrAlias0, true);
  ASSERT_TRUE(peer);
  ASSERT_TRUE(peer->bredr());

  peer->MutLe();
  ASSERT_EQ(TechnologyType::kDualMode, peer->technology());
  ASSERT_EQ(peer, peer_cache()->FindByAddress(kAddress0));
  ASSERT_EQ(DeviceAddress::Type::kBREDR, peer->address().type());

  // Only the LE transport connects in this test, so only add an LE FakePeer to FakeController.
  test_device()->AddPeer(std::make_unique<FakePeer>(kAddress0));

  // Initialize as error to verify that |callback| assigns success.
  hci::Status status(HostError::kFailed);
  LowEnergyConnectionRefPtr conn_ref;
  auto callback = [&status, &conn_ref](auto cb_status, auto cb_conn_ref) {
    ASSERT_TRUE(cb_conn_ref);
    status = cb_status;
    conn_ref = std::move(cb_conn_ref);
    EXPECT_TRUE(conn_ref->active());
  };

  EXPECT_TRUE(connected_peers().empty());
  EXPECT_TRUE(conn_mgr()->Connect(peer->identifier(), callback));
  EXPECT_EQ(Peer::ConnectionState::kInitializing, peer->le()->connection_state());

  RunLoopUntilIdle();

  EXPECT_TRUE(status);
  EXPECT_EQ(1u, connected_peers().size());
  EXPECT_EQ(1u, connected_peers().count(kAddress0));

  ASSERT_TRUE(conn_ref);
  EXPECT_TRUE(conn_ref->active());
  EXPECT_EQ(peer->identifier(), conn_ref->peer_identifier());
  EXPECT_FALSE(peer->temporary());
  EXPECT_EQ(Peer::ConnectionState::kConnected, peer->le()->connection_state());

  conn_ref = nullptr;
  RunLoopUntilIdle();
  EXPECT_EQ(0u, connected_peers().size());
}