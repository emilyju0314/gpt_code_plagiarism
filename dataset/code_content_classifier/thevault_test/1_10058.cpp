rtc::scoped_ptr<MockAudioEncoder> CreateMockEncoder() {
  auto enc = rtc_make_scoped_ptr(new MockAudioEncoder);
  EXPECT_CALL(*enc, SampleRateHz()).WillRepeatedly(Return(8000));
  EXPECT_CALL(*enc, NumChannels()).WillRepeatedly(Return(1));
  EXPECT_CALL(*enc, Max10MsFramesInAPacket()).WillRepeatedly(Return(1));
  EXPECT_CALL(*enc, Die());
  return enc;
}