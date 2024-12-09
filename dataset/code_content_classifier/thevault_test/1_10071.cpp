TEST_F(CodecBeforeStreamingTest, GetRecPayloadTypeFailsForInvalidCodecName) {
  strcpy(codec_instance_.plname, "SomeInvalidCodecName");

  // Should fail since the codec name is invalid.
  EXPECT_NE(0, voe_codec_->GetRecPayloadType(channel_, codec_instance_));
}