TEST_P(QuicStreamIdManagerTest, IsIncomingStreamIdValidAtLimit) {
  QuicStreamId stream_id = GetNthIncomingStreamId(
      stream_id_manager_.incoming_actual_max_streams() - 1);
  EXPECT_TRUE(
      stream_id_manager_.MaybeIncreaseLargestPeerStreamId(stream_id, nullptr));
}