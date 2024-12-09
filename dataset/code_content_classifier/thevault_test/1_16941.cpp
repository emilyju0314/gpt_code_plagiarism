TEST_F(GeneralLossAlgorithmTest, NackRetransmit1PacketWith1StretchAck) {
  const size_t kNumSentPackets = 10;
  // Transmit 10 packets.
  for (size_t i = 1; i <= kNumSentPackets; ++i) {
    SendDataPacket(i);
  }
  AckedPacketVector packets_acked;
  // Nack the first packet 3 times in a single StretchAck.
  unacked_packets_.RemoveFromInFlight(QuicPacketNumber(2));
  packets_acked.push_back(AckedPacket(
      QuicPacketNumber(2), kMaxOutgoingPacketSize, QuicTime::Zero()));
  unacked_packets_.RemoveFromInFlight(QuicPacketNumber(3));
  packets_acked.push_back(AckedPacket(
      QuicPacketNumber(3), kMaxOutgoingPacketSize, QuicTime::Zero()));
  unacked_packets_.RemoveFromInFlight(QuicPacketNumber(4));
  packets_acked.push_back(AckedPacket(
      QuicPacketNumber(4), kMaxOutgoingPacketSize, QuicTime::Zero()));
  VerifyLosses(4, packets_acked, {1});
  EXPECT_EQ(QuicTime::Zero(), loss_algorithm_.GetLossTimeout());
}