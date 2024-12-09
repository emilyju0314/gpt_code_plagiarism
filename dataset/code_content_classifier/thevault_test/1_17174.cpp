TEST_P(QuicStreamIdManagerTest, ProcessStreamsBlockedNoOp) {
  QuicStreamCount stream_count =
      stream_id_manager_.incoming_initial_max_open_streams();
  QuicStreamsBlockedFrame frame(0, stream_count, IsUnidirectional());
  EXPECT_CALL(delegate_, SendMaxStreams(_, _)).Times(0);
}