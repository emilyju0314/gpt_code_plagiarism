TEST_F(DtmfTest, ManualCanChangeDtmfPayloadType) {
  webrtc::CodecInst codec_instance = webrtc::CodecInst();

  TEST_LOG("Changing DTMF payload type.\n");

  // Start by modifying the receiving side.
  for (int i = 0; i < voe_codec_->NumOfCodecs(); i++) {
    EXPECT_EQ(0, voe_codec_->GetCodec(i, codec_instance));
    if (!_stricmp("telephone-event", codec_instance.plname)) {
      codec_instance.pltype = 88;  // Use 88 instead of default 106.
      EXPECT_EQ(0, voe_base_->StopSend(channel_));
      EXPECT_EQ(0, voe_base_->StopPlayout(channel_));
      EXPECT_EQ(0, voe_base_->StopReceive(channel_));
      EXPECT_EQ(0, voe_codec_->SetRecPayloadType(channel_, codec_instance));
      EXPECT_EQ(0, voe_base_->StartReceive(channel_));
      EXPECT_EQ(0, voe_base_->StartPlayout(channel_));
      EXPECT_EQ(0, voe_base_->StartSend(channel_));
      break;
    }
  }

  Sleep(500);

  // Next, we must modify the sending side as well.
  EXPECT_EQ(0, voe_dtmf_->SetSendTelephoneEventPayloadType(
      channel_, codec_instance.pltype));

  RunSixteenDtmfEvents(true);

  EXPECT_EQ(0, voe_dtmf_->SetDtmfFeedbackStatus(true, false));
}