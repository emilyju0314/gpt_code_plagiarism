TEST_F(PacketManipulatorTest, BurstDropNinePackets) {
  // Create a longer packet data structure (10 packets)
  const int kNbrPackets = 10;
  const size_t kDataLength = kPacketSizeInBytes * kNbrPackets;
  uint8_t data[kDataLength];
  uint8_t* data_pointer = data;
  // Fill with 0s, 1s and so on to be able to easily verify which were dropped:
  for (int i = 0; i < kNbrPackets; ++i) {
    memset(data_pointer + i * kPacketSizeInBytes, i, kPacketSizeInBytes);
  }
  // Overwrite the defaults from the test fixture:
  image_._buffer = data;
  image_._length = kDataLength;
  image_._size = kDataLength;

  drop_config_.packet_loss_probability = 0.5;
  drop_config_.packet_loss_burst_length = 5;
  drop_config_.packet_loss_mode = kBurst;
  PredictivePacketManipulator manipulator(&packet_reader_, drop_config_);
  manipulator.AddRandomResult(1.0);
  manipulator.AddRandomResult(0.3);  // less than 0.5 will cause packet loss
  for (int i = 0; i < kNbrPackets - 2; ++i) {
    manipulator.AddRandomResult(1.0);
  }

  // Execute the test target method:
  int nbr_packets_dropped = manipulator.ManipulatePackets(&image_);

  // Should discard every packet after the first one.
  VerifyPacketLoss(9, nbr_packets_dropped, kPacketSizeInBytes, data, image_);
}