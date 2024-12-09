TEST_P(AudioDeviceTest, DISABLED_MeasureLoopbackLatency) {
  EXPECT_EQ(recording_channels(), playout_channels());
  EXPECT_EQ(recording_sample_rate(), playout_sample_rate());
  NiceMock<MockAudioTransport> mock(kPlayout | kRecording);
  rtc::scoped_ptr<LatencyMeasuringAudioStream> latency_audio_stream(
      new LatencyMeasuringAudioStream(playout_frames_per_buffer()));
  mock.HandleCallbacks(test_is_done_.get(),
                       latency_audio_stream.get(),
                       kMeasureLatencyTimeInSec * kNumCallbacksPerSecond);
  EXPECT_EQ(0, audio_device()->RegisterAudioCallback(&mock));
  StartRecording();
  StartPlayout();
  test_is_done_->Wait(std::max(kTestTimeOutInMilliseconds,
                               1000 * kMeasureLatencyTimeInSec));
  StopPlayout();
  StopRecording();
  // Verify that the correct number of transmitted impulses are detected.
  EXPECT_EQ(latency_audio_stream->num_latency_values(),
            kImpulseFrequencyInHz * kMeasureLatencyTimeInSec - 1);
  latency_audio_stream->PrintResults();
}