TEST_F(UnwindOfflineTest, bad_eh_frame_hdr_arm64) {
  std::string error_msg;
  if (!offline_utils_.Init({.offline_files_dir = "bad_eh_frame_hdr_arm64/", .arch = ARCH_ARM64},
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
  EXPECT_EQ(0x60a9fdf550U, unwinder.frames()[0].pc);
  EXPECT_EQ(0x7fdd141990U, unwinder.frames()[0].sp);
  EXPECT_EQ(0x60a9fdf568U, unwinder.frames()[1].pc);
  EXPECT_EQ(0x7fdd1419a0U, unwinder.frames()[1].sp);
  EXPECT_EQ(0x60a9fdf57cU, unwinder.frames()[2].pc);
  EXPECT_EQ(0x7fdd1419b0U, unwinder.frames()[2].sp);
  EXPECT_EQ(0x60a9fdf590U, unwinder.frames()[3].pc);
  EXPECT_EQ(0x7fdd1419c0U, unwinder.frames()[3].sp);
  EXPECT_EQ(0x7542d68e98U, unwinder.frames()[4].pc);
  EXPECT_EQ(0x7fdd1419d0U, unwinder.frames()[4].sp);
}