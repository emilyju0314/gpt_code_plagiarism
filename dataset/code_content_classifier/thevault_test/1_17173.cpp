TEST_P(QuicStreamIdManagerTest, ProcessStreamsBlockedOk) {
  QuicStreamCount stream_count =
      stream_id_manager_.incoming_initial_max_open_streams();
  QuicStreamsBlockedFrame frame(0, stream_count - 1, IsUnidirectional());
  // We have notified peer about current max.
  EXPECT_CALL(delegate_, SendMaxStreams(stream_count, IsUnidirectional()))
      .Times(0);
  std::string error_details;
  EXPECT_TRUE(stream_id_manager_.OnStreamsBlockedFrame(frame, &error_details));
}