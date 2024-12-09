TEST_P(QuicStreamIdManagerTest, ExtremeMaybeIncreaseLargestPeerStreamId) {
  QuicStreamId too_big_stream_id = GetNthIncomingStreamId(
      stream_id_manager_.incoming_actual_max_streams() + 20);

  std::string error_details;
  EXPECT_FALSE(stream_id_manager_.MaybeIncreaseLargestPeerStreamId(
      too_big_stream_id, &error_details));
  EXPECT_EQ(error_details,
            absl::StrCat("Stream id ", too_big_stream_id,
                         " would exceed stream count limit 100"));
}