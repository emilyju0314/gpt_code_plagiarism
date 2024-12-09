static String ExitSummary(int exit_code) {
  Message m;
#if GTEST_OS_WINDOWS
  m << "Exited with exit status " << exit_code;
#else
  if (WIFEXITED(exit_code)) {
    m << "Exited with exit status " << WEXITSTATUS(exit_code);
  } else if (WIFSIGNALED(exit_code)) {
    m << "Terminated by signal " << WTERMSIG(exit_code);
  }
#ifdef WCOREDUMP
  if (WCOREDUMP(exit_code)) {
    m << " (core dumped)";
  }
#endif
#endif  // GTEST_OS_WINDOWS
  return m.GetString();
}