TEST_F(PacketManipulatorTest, UniformDropSinglePacket) {
  drop_config_.packet_loss_probability = 0.5;
  PredictivePacketManipulator manipulator(&packet_reader_, drop_config_);
  manipulator.AddRandomResult(1.0);
  manipulator.AddRandomResult(0.3);  // less than 0.5 will cause packet loss
  manipulator.AddRandomResult(1.0);

  // Execute the test target method:
  int nbr_packets_dropped = manipulator.ManipulatePackets(&image_);

  // Since we setup the predictive packet manipulator, it will throw away the
  // second packet. The third packet is also lost because when we have lost one,
  // the remains shall also be discarded (in the current implementation).
  VerifyPacketLoss(2, nbr_packets_dropped, kPacketSizeInBytes, packet1_,
                   image_);
}