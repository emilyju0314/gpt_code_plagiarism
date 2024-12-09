TEST_F(BweReceiverTest, PacketLossUnorderedPackets) {
  size_t num_packets = bwe_receiver_.GetSetCapacity() / 2;
  std::vector<uint16_t> sequence_numbers;

  for (size_t i = 0; i < num_packets; ++i) {
    sequence_numbers.push_back(static_cast<uint16_t>(i + 1));
  }

  random_shuffle(sequence_numbers.begin(), sequence_numbers.end());

  for (size_t i = 0; i < num_packets; ++i) {
    const MediaPacket media_packet(kFlowId, 0, 0, sequence_numbers[i]);
    // Arrival time = 0, all packets will be considered.
    bwe_receiver_.ReceivePacket(0, media_packet);
  }

  EXPECT_EQ(bwe_receiver_.RecentPacketLossRatio(), 0.0f);
}