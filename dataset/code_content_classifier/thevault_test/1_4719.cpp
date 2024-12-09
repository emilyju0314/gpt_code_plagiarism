TEST(VerifyBionicTermination, local_terminate) {
  std::unique_ptr<Regs> regs(Regs::CreateFromLocal());

  UnwinderFromPid unwinder(512, getpid());
  unwinder.SetRegs(regs.get());

  RegsGetLocal(regs.get());
  unwinder.Unwind();
  ASSERT_LT(0U, unwinder.NumFrames());

  SCOPED_TRACE(DumpFrames(unwinder));

  // Look for the frame that includes __libc_init, there should only
  // be one and it should be the last.
  bool found = false;
  const std::vector<FrameData>& frames = unwinder.frames();
  for (size_t i = 0; i < unwinder.NumFrames(); i++) {
    const FrameData& frame = frames[i];
    if (frame.function_name == "__libc_init" && !frame.map_name.empty() &&
        std::string("libc.so") == basename(frame.map_name.c_str())) {
      ASSERT_EQ(unwinder.NumFrames(), i + 1) << "__libc_init is not last frame.";
      ASSERT_NO_FATAL_FAILURE(VerifyReturnAddress(frame));
      found = true;
    }
  }
  ASSERT_TRUE(found) << "Unable to find libc.so:__libc_init frame\n";
}