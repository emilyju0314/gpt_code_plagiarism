TEST_F(HardwareBeforeStreamingTest,
       SetAudioDeviceLayerFailsSinceTheVoiceEngineHasBeenInitialized) {
  EXPECT_NE(0, voe_hardware_->SetAudioDeviceLayer(kAudioPlatformDefault));
  EXPECT_EQ(VE_ALREADY_INITED, voe_base_->LastError());
}