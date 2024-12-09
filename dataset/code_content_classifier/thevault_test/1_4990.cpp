TEST(Pipes, Echo) {
  int pipe_a[2];
  int pipe_b[2];
  // Create two pipe pairs pipe_a[1] ->  pipe_a[0]
  //                       pipe_b[1] ->  pipe_b[0]
  ASSERT_EQ(0, pipe(pipe_a));
  ASSERT_EQ(0, pipe(pipe_b));
  pid_t pid = vfork();
  ASSERT_GE(pid, 0);
  if (!pid) {
    // Dup two ends of the pipes into stdin + stdout of the echo process.
    ASSERT_EQ(0, dup2(pipe_a[0], 0));
    EXPECT_EQ(0, close(pipe_a[0]));
    EXPECT_EQ(0, close(pipe_a[1]));
    EXPECT_EQ(1, dup2(pipe_b[1], 1));
    EXPECT_EQ(0, close(pipe_b[0]));
    EXPECT_EQ(0, close(pipe_b[1]));
    execlp(argv0, argv0, "pipes", NULL);
    // Don't get here.
    ASSERT_TRUE(false);
  }

  EXPECT_EQ(0, close(pipe_a[0]));
  EXPECT_EQ(0, close(pipe_b[1]));

  const char test_message[] = "test message";

  // Write to pipe_a.
  int len = write(pipe_a[1], test_message, strlen(test_message));
  EXPECT_EQ(strlen(test_message), len);
  char buffer[100];
  // Wait for an echo back on pipe_b.
  int total = 0;
  while (total < strlen(test_message)) {
    len = read(pipe_b[0], buffer + total, sizeof(buffer));
    ASSERT_GE(len, 0);
    if (len == 0) break;
    total += len;
  }
  EXPECT_EQ(strlen(test_message), len);
  EXPECT_TRUE(memcmp(buffer, test_message, len) == 0);

  EXPECT_EQ(0, close(pipe_a[1]));
  EXPECT_EQ(0, close(pipe_b[0]));
}