TEST_P(AudioDeviceTest, StartPlayoutAndRecordingVerifyCallbacks) {
  MockAudioTransport mock(kPlayout | kRecording);
  mock.HandleCallbacks(test_is_done_.get(), nullptr,  kNumCallbacks);
  EXPECT_CALL(mock, NeedMorePlayData(playout_frames_per_buffer(),
                                     kBytesPerSample,
                                     playout_channels(),
                                     playout_sample_rate(),
                                     NotNull(),
                                     _, _, _))
      .Times(AtLeast(kNumCallbacks));
  EXPECT_CALL(mock, RecordedDataIsAvailable(NotNull(),
                                            recording_frames_per_buffer(),
                                            kBytesPerSample,
                                            recording_channels(),
                                            recording_sample_rate(),
                                            Gt(kFixedRecordingDelay),
                                            0,
                                            0,
                                            false,
                                            _))
      .Times(AtLeast(kNumCallbacks));
  EXPECT_EQ(0, audio_device()->RegisterAudioCallback(&mock));
  StartPlayout();
  StartRecording();
  test_is_done_->Wait(kTestTimeOutInMilliseconds);
  StopRecording();
  StopPlayout();
}