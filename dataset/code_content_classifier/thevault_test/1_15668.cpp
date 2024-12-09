TEST_P(AudioDeviceTest, StartPlayoutVerifyCallbacks) {
  MockAudioTransport mock(kPlayout);
  mock.HandleCallbacks(test_is_done_.get(), nullptr, kNumCallbacks);
  EXPECT_CALL(mock, NeedMorePlayData(playout_frames_per_buffer(),
                                     kBytesPerSample,
                                     playout_channels(),
                                     playout_sample_rate(),
                                     NotNull(),
                                     _, _, _))
      .Times(AtLeast(kNumCallbacks));
  EXPECT_EQ(0, audio_device()->RegisterAudioCallback(&mock));
  StartPlayout();
  test_is_done_->Wait(kTestTimeOutInMilliseconds);
  StopPlayout();
}