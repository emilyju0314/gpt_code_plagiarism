TEST(Pipes, CloseExec) {
  int p[2];
  ASSERT_EQ(0, pipe(p));

  char fd1[20];
  sprintf(fd1, "%d", p[0]);
  char fd2[20];
  sprintf(fd2, "%d", p[1]);

  fcntl(p[1], F_SETFD, fcntl(p[1], F_GETFD) | FD_CLOEXEC);

  pid_t pid = vfork();
  ASSERT_GE(pid, 0);
  if (!pid) {
    // When running in the child.
    execlp(argv0, argv0, "cloexec_check", fd1, fd2, NULL);
    // Don't get here.
    ASSERT_TRUE(false);
  }

  EXPECT_EQ(0, close(p[0]));
  EXPECT_EQ(0, close(p[1]));

  int status;
  pid_t npid = waitpid(pid, &status, 0);
  EXPECT_EQ(pid, npid);
  EXPECT_TRUE(WIFEXITED(status));
  EXPECT_EQ(42, WEXITSTATUS(status));
}