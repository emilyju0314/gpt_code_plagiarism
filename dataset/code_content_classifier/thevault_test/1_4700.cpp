TEST_F(UnwindOfflineTest, eh_frame_hdr_begin_x86_64) {
  std::string error_msg;
  if (!offline_utils_.Init({.offline_files_dir = "eh_frame_hdr_begin_x86_64/", .arch = ARCH_X86_64},
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
  EXPECT_EQ(0x561550b17a80U, unwinder.frames()[0].pc);
  EXPECT_EQ(0x7ffcc8596ce8U, unwinder.frames()[0].sp);
  EXPECT_EQ(0x561550b17dd9U, unwinder.frames()[1].pc);
  EXPECT_EQ(0x7ffcc8596cf0U, unwinder.frames()[1].sp);
  EXPECT_EQ(0x561550b1821eU, unwinder.frames()[2].pc);
  EXPECT_EQ(0x7ffcc8596f40U, unwinder.frames()[2].sp);
  EXPECT_EQ(0x561550b183edU, unwinder.frames()[3].pc);
  EXPECT_EQ(0x7ffcc8597190U, unwinder.frames()[3].sp);
  EXPECT_EQ(0x7f4de62162b0U, unwinder.frames()[4].pc);
  EXPECT_EQ(0x7ffcc85971a0U, unwinder.frames()[4].sp);
}