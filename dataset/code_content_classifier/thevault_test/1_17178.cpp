TEST_P(QuicStreamIdManagerTest, IsIncomingStreamIdInValidAboveLimit) {
  QuicStreamId stream_id =
      GetNthIncomingStreamId(stream_id_manager_.incoming_actual_max_streams());
  std::string error_details;
  EXPECT_FALSE(stream_id_manager_.MaybeIncreaseLargestPeerStreamId(
      stream_id, &error_details));
  EXPECT_EQ(error_details,
            absl::StrCat("Stream id ", stream_id,
                         " would exceed stream count limit 100"));
}