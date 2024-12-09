void DeathTestImpl::Abort(AbortReason reason) {
  // The parent process considers the death test to be a failure if
  // it finds any data in our pipe.  So, here we write a single flag byte
  // to the pipe, then exit.
  const char status_ch =
      reason == TEST_DID_NOT_DIE ? kDeathTestLived : kDeathTestReturned;
  GTEST_DEATH_TEST_CHECK_SYSCALL_(posix::Write(write_fd(), &status_ch, 1));
  GTEST_DEATH_TEST_CHECK_SYSCALL_(posix::Close(write_fd()));
  _exit(1);  // Exits w/o any normal exit hooks (we were supposed to crash)
}