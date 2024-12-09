TEST_P(AudioDeviceTest, AudioParameters) {
  EXPECT_NE(0, playout_sample_rate());
  PRINT("%splayout_sample_rate: %d\n", kTag, playout_sample_rate());
  EXPECT_NE(0, recording_sample_rate());
  PRINT("%splayout_sample_rate: %d\n", kTag, recording_sample_rate());
  EXPECT_NE(0, playout_channels());
  PRINT("%splayout_channels: %d\n", kTag, playout_channels());
  EXPECT_NE(0, recording_channels());
  PRINT("%srecording_channels: %d\n", kTag, recording_channels());
}