TEST_P(QuicStreamIdManagerTest, MaxStreamsSlidingWindow) {
  QuicStreamCount first_advert =
      stream_id_manager_.incoming_advertised_max_streams();

  // Open/close enough streams to shrink the window without causing a MAX
  // STREAMS to be generated. The loop
  // will make that many stream IDs available, so the last CloseStream should
  // cause a MAX STREAMS frame to be generated.
  int i =
      static_cast<int>(stream_id_manager_.incoming_initial_max_open_streams() /
                       GetQuicFlag(FLAGS_quic_max_streams_window_divisor));
  QuicStreamId id =
      QuicStreamIdManagerPeer::GetFirstIncomingStreamId(&stream_id_manager_);
  EXPECT_CALL(delegate_, SendMaxStreams(first_advert + i, IsUnidirectional()));
  while (i) {
    EXPECT_TRUE(
        stream_id_manager_.MaybeIncreaseLargestPeerStreamId(id, nullptr));
    stream_id_manager_.OnStreamClosed(id);
    i--;
    id += QuicUtils::StreamIdDelta(transport_version());
  }
}