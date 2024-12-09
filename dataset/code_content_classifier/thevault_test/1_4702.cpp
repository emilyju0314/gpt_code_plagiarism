TEST_F(UnwindOfflineTest, signal_fde_x86) {
  std::string error_msg;
  if (!offline_utils_.Init({.offline_files_dir = "signal_fde_x86/", .arch = ARCH_X86}, &error_msg))
    FAIL() << error_msg;

  Unwinder unwinder(128, offline_utils_.GetMaps(), offline_utils_.GetRegs(),
                    offline_utils_.GetProcessMemory());
  unwinder.Unwind();

  size_t expected_num_frames;
  if (!offline_utils_.GetExpectedNumFrames(&expected_num_frames, &error_msg)) FAIL() << error_msg;
  std::string expected_frame_info;
  if (!GetExpectedSamplesFrameInfo(&expected_frame_info, &error_msg)) FAIL() << error_msg;

  std::string frame_info(DumpFrames(unwinder));
  ASSERT_EQ(expected_num_frames, unwinder.NumFrames()) << "Unwind:\n" << frame_info;
  EXPECT_EQ(expected_frame_info, frame_info);
  EXPECT_EQ(0x5ae0d4d9U, unwinder.frames()[0].pc);
  EXPECT_EQ(0xecb37188U, unwinder.frames()[0].sp);
  EXPECT_EQ(0x5ae0d4fcU, unwinder.frames()[1].pc);
  EXPECT_EQ(0xecb37190U, unwinder.frames()[1].sp);
  EXPECT_EQ(0x5ae0d52cU, unwinder.frames()[2].pc);
  EXPECT_EQ(0xecb371b0U, unwinder.frames()[2].sp);
  EXPECT_EQ(0x5ae16f62U, unwinder.frames()[3].pc);
  EXPECT_EQ(0xecb371d0U, unwinder.frames()[3].sp);
  EXPECT_EQ(0xec169fb0U, unwinder.frames()[4].pc);
  EXPECT_EQ(0xecb371f0U, unwinder.frames()[4].sp);
  EXPECT_EQ(0x0U, unwinder.frames()[5].pc);
  EXPECT_EQ(0xffcfac6cU, unwinder.frames()[5].sp);
  EXPECT_EQ(0x5ae0d61aU, unwinder.frames()[6].pc);
  EXPECT_EQ(0xffcfac6cU, unwinder.frames()[6].sp);
  EXPECT_EQ(0x5ae0e3aaU, unwinder.frames()[7].pc);
  EXPECT_EQ(0xffcfad60U, unwinder.frames()[7].sp);
  EXPECT_EQ(0x5ae0e3eaU, unwinder.frames()[8].pc);
  EXPECT_EQ(0xffcfad90U, unwinder.frames()[8].sp);
  EXPECT_EQ(0x5ae13444U, unwinder.frames()[9].pc);
  EXPECT_EQ(0xffcfadc0U, unwinder.frames()[9].sp);
  EXPECT_EQ(0x5ae145b8U, unwinder.frames()[10].pc);
  EXPECT_EQ(0xffcfb020U, unwinder.frames()[10].sp);
  EXPECT_EQ(0x5ae93a19U, unwinder.frames()[11].pc);
  EXPECT_EQ(0xffcfb050U, unwinder.frames()[11].sp);
  EXPECT_EQ(0x5ae938c5U, unwinder.frames()[12].pc);
  EXPECT_EQ(0xffcfb090U, unwinder.frames()[12].sp);
  EXPECT_EQ(0x5ae94d3eU, unwinder.frames()[13].pc);
  EXPECT_EQ(0xffcfb0f0U, unwinder.frames()[13].sp);
  EXPECT_EQ(0x5ae958b4U, unwinder.frames()[14].pc);
  EXPECT_EQ(0xffcfb160U, unwinder.frames()[14].sp);
  EXPECT_EQ(0x5aea4cb0U, unwinder.frames()[15].pc);
  EXPECT_EQ(0xffcfb1d0U, unwinder.frames()[15].sp);
  EXPECT_EQ(0x5aea470fU, unwinder.frames()[16].pc);
  EXPECT_EQ(0xffcfb270U, unwinder.frames()[16].sp);
  EXPECT_EQ(0x5aebc31eU, unwinder.frames()[17].pc);
  EXPECT_EQ(0xffcfb2c0U, unwinder.frames()[17].sp);
  EXPECT_EQ(0x5aebb9e9U, unwinder.frames()[18].pc);
  EXPECT_EQ(0xffcfc3c0U, unwinder.frames()[18].sp);
  EXPECT_EQ(0xec161646U, unwinder.frames()[19].pc);
  EXPECT_EQ(0xffcfc3f0U, unwinder.frames()[19].sp);
}