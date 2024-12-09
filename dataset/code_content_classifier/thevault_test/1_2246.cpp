TEST_F(GAP_LowEnergyConnectionManagerTest, DisconnectCompleteEventWhileRefPending) {
  auto* peer = peer_cache()->NewPeer(kAddress0, true);
  test_device()->AddPeer(std::make_unique<FakePeer>(kAddress0));

  LowEnergyConnectionRefPtr conn_ref;
  auto success_cb = [&conn_ref](auto status, auto cb_conn_ref) {
    ASSERT_TRUE(cb_conn_ref);
    ASSERT_TRUE(status);
    EXPECT_TRUE(cb_conn_ref->active());

    conn_ref = std::move(cb_conn_ref);
  };

  EXPECT_TRUE(conn_mgr()->Connect(peer->identifier(), success_cb));
  RunLoopUntilIdle();
  ASSERT_TRUE(conn_ref);

  // Request a new reference. Disconnect the link before the reference is
  // received.
  size_t ref_cb_count = 0;
  auto ref_cb = [&ref_cb_count](auto status, auto conn_ref) {
    ref_cb_count++;
    EXPECT_FALSE(conn_ref);
    EXPECT_FALSE(status);
    EXPECT_EQ(HostError::kFailed, status.error());
  };

  size_t disconn_cb_count = 0;
  auto disconn_cb = [this, ref_cb, peer, &disconn_cb_count](auto) {
    disconn_cb_count++;
    // The link is gone but conn_mgr() hasn't updated the connection state yet.
    // The request to connect will attempt to add a new reference which will be
    // invalidated before |ref_cb| gets called.
    EXPECT_TRUE(conn_mgr()->Connect(peer->identifier(), ref_cb));
  };
  conn_mgr()->SetDisconnectCallbackForTesting(disconn_cb);

  test_device()->SendDisconnectionCompleteEvent(conn_ref->handle());

  RunLoopUntilIdle();

  EXPECT_EQ(1u, ref_cb_count);
  EXPECT_EQ(1u, disconn_cb_count);
}