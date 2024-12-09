TEST_P(AudioDeviceTest, StartRecordingVerifyCallbacks) {
  MockAudioTransport mock(kRecording);
  mock.HandleCallbacks(test_is_done_.get(), nullptr, kNumCallbacks);
  EXPECT_CALL(mock, RecordedDataIsAvailable(NotNull(),
                                            recording_frames_per_buffer(),
                                            kBytesPerSample,
                                            recording_channels(),
                                            recording_sample_rate(),
                                            kFixedRecordingDelay,
                                            0,
                                            0,
                                            false,
                                            _))
      .Times(AtLeast(kNumCallbacks));

  EXPECT_EQ(0, audio_device()->RegisterAudioCallback(&mock));
  StartRecording();
  test_is_done_->Wait(kTestTimeOutInMilliseconds);
  StopRecording();
}