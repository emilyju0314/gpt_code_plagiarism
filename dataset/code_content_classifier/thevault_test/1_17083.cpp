TEST_F(QuicEndpointTest, WriteBlocked) {
  QuicEndpoint endpoint_a(&simulator_, "Endpoint A", "Endpoint B",
                          Perspective::IS_CLIENT, test::TestConnectionId(42));
  QuicEndpoint endpoint_b(&simulator_, "Endpoint B", "Endpoint A",
                          Perspective::IS_SERVER, test::TestConnectionId(42));
  auto link_a = Link(&endpoint_a, switch_.port(1));
  auto link_b = Link(&endpoint_b, switch_.port(2));

  // Will be owned by the sent packet manager.
  auto* sender = new NiceMock<test::MockSendAlgorithm>();
  EXPECT_CALL(*sender, CanSend(_)).WillRepeatedly(Return(true));
  EXPECT_CALL(*sender, PacingRate(_))
      .WillRepeatedly(Return(10 * kDefaultBandwidth));
  EXPECT_CALL(*sender, BandwidthEstimate())
      .WillRepeatedly(Return(10 * kDefaultBandwidth));
  EXPECT_CALL(*sender, GetCongestionWindow())
      .WillRepeatedly(Return(kMaxOutgoingPacketSize *
                             GetQuicFlag(FLAGS_quic_max_congestion_window)));
  test::QuicConnectionPeer::SetSendAlgorithm(endpoint_a.connection(), sender);

  // First transmit a small, packet-size chunk of data.
  QuicByteCount bytes_to_transfer = 3 * 1024 * 1024;
  endpoint_a.AddBytesToTransfer(bytes_to_transfer);
  QuicTime end_time =
      simulator_.GetClock()->Now() + QuicTime::Delta::FromSeconds(30);
  simulator_.RunUntil([this, &endpoint_b, bytes_to_transfer, end_time]() {
    return endpoint_b.bytes_received() == bytes_to_transfer ||
           simulator_.GetClock()->Now() >= end_time;
  });

  EXPECT_EQ(bytes_to_transfer, endpoint_a.bytes_transferred());
  EXPECT_EQ(bytes_to_transfer, endpoint_b.bytes_received());
  EXPECT_GT(endpoint_a.write_blocked_count(), 0u);
  EXPECT_FALSE(endpoint_a.wrong_data_received());
  EXPECT_FALSE(endpoint_b.wrong_data_received());
}