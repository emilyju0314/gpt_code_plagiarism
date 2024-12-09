TEST_P(AudioDeviceTest, RunPlayoutWithFileAsSource) {
  // TODO(henrika): extend test when mono output is supported.
  EXPECT_EQ(1, playout_channels());
  NiceMock<MockAudioTransport> mock(kPlayout);
  const int num_callbacks = kFilePlayTimeInSec * kNumCallbacksPerSecond;
  std::string file_name = GetFileName(playout_sample_rate());
  rtc::scoped_ptr<FileAudioStream> file_audio_stream(
      new FileAudioStream(num_callbacks, file_name, playout_sample_rate()));
  mock.HandleCallbacks(test_is_done_.get(),
                       file_audio_stream.get(),
                       num_callbacks);
  EXPECT_EQ(0, audio_device()->RegisterAudioCallback(&mock));
  StartPlayout();
  test_is_done_->Wait(kTestTimeOutInMilliseconds);
  StopPlayout();
}