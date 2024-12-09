TEST_F(VolumeTest, VerifyCorrectErrorReturns) {
  // All tests run on correct initialization which eliminates one possible error
  // return. In addition, we assume the audio_device returning values without
  // error, which eliminates another potential error.
  // Left to verify are sanity checks of set parameters.

  // Valid volume range: [0, 255]
  EXPECT_EQ(-1, voe_volume_control_->SetSpeakerVolume(256));
  EXPECT_EQ(-1, voe_volume_control_->SetMicVolume(256));

  // Valid panning rage: [0, 1]
  EXPECT_EQ(-1, voe_volume_control_->SetOutputVolumePan(channel_, -0.1f, 0.5f));
  EXPECT_EQ(-1, voe_volume_control_->SetOutputVolumePan(channel_, 1.1f, 0.5f));
  EXPECT_EQ(-1, voe_volume_control_->SetOutputVolumePan(channel_, 0.5f, -0.1f));
  EXPECT_EQ(-1, voe_volume_control_->SetOutputVolumePan(channel_, 0.5f, 1.1f));
}