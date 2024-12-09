TEST_F(UnwindOfflineTest, signal_fde_x86_64) {
  std::string error_msg;
  if (!offline_utils_.Init({.offline_files_dir = "signal_fde_x86_64/", .arch = ARCH_X86_64},
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
  EXPECT_EQ(0x5bb41271e15bU, unwinder.frames()[0].pc);
  EXPECT_EQ(0x707eb5aa8320U, unwinder.frames()[0].sp);
  EXPECT_EQ(0x5bb41271e168U, unwinder.frames()[1].pc);
  EXPECT_EQ(0x707eb5aa8330U, unwinder.frames()[1].sp);
  EXPECT_EQ(0x5bb41271e178U, unwinder.frames()[2].pc);
  EXPECT_EQ(0x707eb5aa8340U, unwinder.frames()[2].sp);
  EXPECT_EQ(0x5bb412724c77U, unwinder.frames()[3].pc);
  EXPECT_EQ(0x707eb5aa8350U, unwinder.frames()[3].sp);
  EXPECT_EQ(0x707eb2ca5d10U, unwinder.frames()[4].pc);
  EXPECT_EQ(0x707eb5aa8380U, unwinder.frames()[4].sp);
  EXPECT_EQ(0x0U, unwinder.frames()[5].pc);
  EXPECT_EQ(0x7ffcaadde078U, unwinder.frames()[5].sp);
  EXPECT_EQ(0x5bb41271e244U, unwinder.frames()[6].pc);
  EXPECT_EQ(0x7ffcaadde078U, unwinder.frames()[6].sp);
  EXPECT_EQ(0x5bb41271eb44U, unwinder.frames()[7].pc);
  EXPECT_EQ(0x7ffcaadde1a0U, unwinder.frames()[7].sp);
  EXPECT_EQ(0x5bb41271eb64U, unwinder.frames()[8].pc);
  EXPECT_EQ(0x7ffcaadde1c0U, unwinder.frames()[8].sp);
  EXPECT_EQ(0x5bb412722457U, unwinder.frames()[9].pc);
  EXPECT_EQ(0x7ffcaadde1e0U, unwinder.frames()[9].sp);
  EXPECT_EQ(0x5bb412722f67U, unwinder.frames()[10].pc);
  EXPECT_EQ(0x7ffcaadde510U, unwinder.frames()[10].sp);
  EXPECT_EQ(0x5bb412773c38U, unwinder.frames()[11].pc);
  EXPECT_EQ(0x7ffcaadde530U, unwinder.frames()[11].sp);
  EXPECT_EQ(0x5bb412774f9aU, unwinder.frames()[12].pc);
  EXPECT_EQ(0x7ffcaadde560U, unwinder.frames()[12].sp);
  EXPECT_EQ(0x5bb412775a46U, unwinder.frames()[13].pc);
  EXPECT_EQ(0x7ffcaadde5b0U, unwinder.frames()[13].sp);
  EXPECT_EQ(0x5bb4127844c6U, unwinder.frames()[14].pc);
  EXPECT_EQ(0x7ffcaadde5f0U, unwinder.frames()[14].sp);
  EXPECT_EQ(0x5bb412783f61U, unwinder.frames()[15].pc);
  EXPECT_EQ(0x7ffcaadde6c0U, unwinder.frames()[15].sp);
  EXPECT_EQ(0x5bb41279a155U, unwinder.frames()[16].pc);
  EXPECT_EQ(0x7ffcaadde720U, unwinder.frames()[16].sp);
  EXPECT_EQ(0x707eb2c9c405U, unwinder.frames()[17].pc);
  EXPECT_EQ(0x7ffcaaddf870U, unwinder.frames()[17].sp);
}