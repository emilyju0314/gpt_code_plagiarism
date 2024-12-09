TEST_F(GAP_LowEnergyConnectionManagerTest, DisconnectEvent) {
  auto* peer = peer_cache()->NewPeer(kAddress0, true);

  test_device()->AddPeer(std::make_unique<FakePeer>(kAddress0));

  int closed_count = 0;
  auto closed_cb = [&closed_count] { closed_count++; };

  std::vector<LowEnergyConnectionRefPtr> conn_refs;
  auto success_cb = [&conn_refs, &closed_cb](auto status, auto conn_ref) {
    EXPECT_TRUE(status);
    ASSERT_TRUE(conn_ref);
    conn_ref->set_closed_callback(closed_cb);
    conn_refs.push_back(std::move(conn_ref));
  };

  // Issue two connection refs.
  EXPECT_TRUE(conn_mgr()->Connect(peer->identifier(), success_cb));
  EXPECT_TRUE(conn_mgr()->Connect(peer->identifier(), success_cb));

  RunLoopUntilIdle();

  ASSERT_EQ(2u, conn_refs.size());

  // This makes FakeController send us HCI Disconnection Complete events.
  test_device()->Disconnect(kAddress0);

  RunLoopUntilIdle();

  EXPECT_EQ(2, closed_count);
}