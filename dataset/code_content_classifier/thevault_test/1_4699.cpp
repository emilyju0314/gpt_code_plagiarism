TEST_F(UnwindOfflineTest, debug_frame_first_x86) {
  std::string error_msg;
  if (!offline_utils_.Init({.offline_files_dir = "debug_frame_first_x86/", .arch = ARCH_X86},
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
  EXPECT_EQ(0x56598685U, unwinder.frames()[0].pc);
  EXPECT_EQ(0xffcf9e38U, unwinder.frames()[0].sp);
  EXPECT_EQ(0x565986b7U, unwinder.frames()[1].pc);
  EXPECT_EQ(0xffcf9e50U, unwinder.frames()[1].sp);
  EXPECT_EQ(0x565986d7U, unwinder.frames()[2].pc);
  EXPECT_EQ(0xffcf9e60U, unwinder.frames()[2].sp);
  EXPECT_EQ(0x565986f7U, unwinder.frames()[3].pc);
  EXPECT_EQ(0xffcf9e70U, unwinder.frames()[3].sp);
  EXPECT_EQ(0xf744a275U, unwinder.frames()[4].pc);
  EXPECT_EQ(0xffcf9e80U, unwinder.frames()[4].sp);
}