TEST_F(UnwindOfflineTest, debug_frame_load_bias_arm) {
  std::string error_msg;
  if (!offline_utils_.Init({.offline_files_dir = "debug_frame_load_bias_arm/", .arch = ARCH_ARM},
                           &error_msg))
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
  EXPECT_EQ(0xf0be238cU, unwinder.frames()[0].pc);
  EXPECT_EQ(0xffd4a638U, unwinder.frames()[0].sp);
  EXPECT_EQ(0xf0bb240fU, unwinder.frames()[1].pc);
  EXPECT_EQ(0xffd4a638U, unwinder.frames()[1].sp);
  EXPECT_EQ(0xf1a75535U, unwinder.frames()[2].pc);
  EXPECT_EQ(0xffd4a650U, unwinder.frames()[2].sp);
  EXPECT_EQ(0xf1a75633U, unwinder.frames()[3].pc);
  EXPECT_EQ(0xffd4a6b0U, unwinder.frames()[3].sp);
  EXPECT_EQ(0xf1a75b57U, unwinder.frames()[4].pc);
  EXPECT_EQ(0xffd4a6d0U, unwinder.frames()[4].sp);
  EXPECT_EQ(0x8d1cc21U, unwinder.frames()[5].pc);
  EXPECT_EQ(0xffd4a6e8U, unwinder.frames()[5].sp);
  EXPECT_EQ(0xf0c15b89U, unwinder.frames()[6].pc);
  EXPECT_EQ(0xffd4a700U, unwinder.frames()[6].sp);
  EXPECT_EQ(0x8d1cb77U, unwinder.frames()[7].pc);
  EXPECT_EQ(0xffd4a718U, unwinder.frames()[7].sp);
}