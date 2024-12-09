TEST_P(AudioDeviceTest, RunPlayoutAndRecordingInFullDuplex) {
  EXPECT_EQ(recording_channels(), playout_channels());
  EXPECT_EQ(recording_sample_rate(), playout_sample_rate());
  NiceMock<MockAudioTransport> mock(kPlayout | kRecording);
  rtc::scoped_ptr<FifoAudioStream> fifo_audio_stream(
      new FifoAudioStream(playout_frames_per_buffer()));
  mock.HandleCallbacks(test_is_done_.get(),
                       fifo_audio_stream.get(),
                       kFullDuplexTimeInSec * kNumCallbacksPerSecond);
  EXPECT_EQ(0, audio_device()->RegisterAudioCallback(&mock));
  StartRecording();
  StartPlayout();
  test_is_done_->Wait(std::max(kTestTimeOutInMilliseconds,
                               1000 * kFullDuplexTimeInSec));
  StopPlayout();
  StopRecording();
  EXPECT_LE(fifo_audio_stream->average_size(), 10);
  EXPECT_LE(fifo_audio_stream->largest_size(), 20);
}