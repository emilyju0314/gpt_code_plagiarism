TEST_P(QuicStreamIdManagerTest, IsIncomingStreamIdValidBelowLimit) {
  QuicStreamId stream_id = GetNthIncomingStreamId(
      stream_id_manager_.incoming_actual_max_streams() - 2);
  EXPECT_TRUE(
      stream_id_manager_.MaybeIncreaseLargestPeerStreamId(stream_id, nullptr));
}