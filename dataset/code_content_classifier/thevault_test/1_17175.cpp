TEST_P(QuicStreamIdManagerTest, ProcessStreamsBlockedTooBig) {
  EXPECT_CALL(delegate_, SendMaxStreams(_, _)).Times(0);
  QuicStreamCount stream_count =
      stream_id_manager_.incoming_initial_max_open_streams() + 1;
  QuicStreamsBlockedFrame frame(0, stream_count, IsUnidirectional());
  std::string error_details;
  EXPECT_FALSE(stream_id_manager_.OnStreamsBlockedFrame(frame, &error_details));
  EXPECT_EQ(
      error_details,
      "StreamsBlockedFrame's stream count 101 exceeds incoming max stream 100");
}