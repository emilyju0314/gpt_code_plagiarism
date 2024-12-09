TEST_F(QuicEndpointTest, Competition) {
  auto endpoint_a = std::make_unique<QuicEndpoint>(
      &simulator_, "Endpoint A", "Endpoint D (A)", Perspective::IS_CLIENT,
      test::TestConnectionId(42));
  auto endpoint_b = std::make_unique<QuicEndpoint>(
      &simulator_, "Endpoint B", "Endpoint D (B)", Perspective::IS_CLIENT,
      test::TestConnectionId(43));
  auto endpoint_c = std::make_unique<QuicEndpoint>(
      &simulator_, "Endpoint C", "Endpoint D (C)", Perspective::IS_CLIENT,
      test::TestConnectionId(44));
  auto endpoint_d_a = std::make_unique<QuicEndpoint>(
      &simulator_, "Endpoint D (A)", "Endpoint A", Perspective::IS_SERVER,
      test::TestConnectionId(42));
  auto endpoint_d_b = std::make_unique<QuicEndpoint>(
      &simulator_, "Endpoint D (B)", "Endpoint B", Perspective::IS_SERVER,
      test::TestConnectionId(43));
  auto endpoint_d_c = std::make_unique<QuicEndpoint>(
      &simulator_, "Endpoint D (C)", "Endpoint C", Perspective::IS_SERVER,
      test::TestConnectionId(44));
  QuicEndpointMultiplexer endpoint_d(
      "Endpoint D",
      {endpoint_d_a.get(), endpoint_d_b.get(), endpoint_d_c.get()});

  // Create links with slightly different RTTs in order to avoid pathological
  // side-effects of packets entering the queue at the exactly same time.
  auto link_a = CustomLink(endpoint_a.get(), switch_.port(1), 0);
  auto link_b = CustomLink(endpoint_b.get(), switch_.port(2), 1);
  auto link_c = CustomLink(endpoint_c.get(), switch_.port(3), 2);
  auto link_d = Link(&endpoint_d, switch_.port(4));

  endpoint_a->AddBytesToTransfer(2 * 1024 * 1024);
  endpoint_b->AddBytesToTransfer(2 * 1024 * 1024);
  endpoint_c->AddBytesToTransfer(2 * 1024 * 1024);
  QuicTime end_time =
      simulator_.GetClock()->Now() + QuicTime::Delta::FromSeconds(12);
  simulator_.RunUntil(
      [this, end_time]() { return simulator_.GetClock()->Now() >= end_time; });

  for (QuicEndpoint* endpoint :
       {endpoint_a.get(), endpoint_b.get(), endpoint_c.get()}) {
    EXPECT_EQ(2u * 1024u * 1024u, endpoint->bytes_transferred());
    EXPECT_GE(endpoint->connection()->GetStats().packets_lost, 0u);
  }
  for (QuicEndpoint* endpoint :
       {endpoint_d_a.get(), endpoint_d_b.get(), endpoint_d_c.get()}) {
    EXPECT_EQ(2u * 1024u * 1024u, endpoint->bytes_received());
    EXPECT_FALSE(endpoint->wrong_data_received());
  }
}