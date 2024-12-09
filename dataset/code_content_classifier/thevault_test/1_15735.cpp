static string GenerateStackTrace(const string &exe_path,
                                 const pid_t   pid) {
  int retval;
  string result = "";

  // re-gain root permissions to allow for ptrace of died cvmfs2 process
  const bool retrievable = true;
  if (!SwitchCredentials(0, getgid(), retrievable)) {
    result += "failed to re-gain root permissions... still give it a try\n";
  }

  // run gdb and attach to the dying cvmfs2 process
  int fd_stdin;
  int fd_stdout;
  int fd_stderr;
  std::vector<std::string> argv; // TODO: C++11 initializer list...
  argv.push_back("-q");
  argv.push_back("-n");
  argv.push_back(exe_path);
  argv.push_back(StringifyInt(pid));
  pid_t gdb_pid;
  retval = ExecuteBinary(&fd_stdin,
                         &fd_stdout,
                         &fd_stderr,
                          "gdb",
                          argv,
                         &gdb_pid);
  assert(retval);

  // skip the gdb startup output
  ReadUntilGdbPrompt(fd_stdout);

  // send stacktrace command to gdb
  const string gdb_cmd = "thread apply all bt\n" // backtrace all threads
                         "quit\n";               // stop gdb
  WritePipe(fd_stdin, gdb_cmd.data(), gdb_cmd.length());

  // read the stack trace from the stdout of our gdb process
  result += ReadUntilGdbPrompt(fd_stdout) + "\n\n";
  close(fd_stderr);
  close(fd_stdout);
  close(fd_stdin);

  // make sure gdb has quitted (wait for it for a short while)
  unsigned int timeout = 15;
  while (timeout > 0 && kill(gdb_pid, 0) == 0) {
    --timeout;
    SafeSleepMs(1000);
  }

  // when the timeout expired, gdb probably hangs... we need to kill it
  if (timeout == 0) {
    result += "gdb did not exit as expected. sending SIGKILL... ";
    result += (kill(gdb_pid, SIGKILL) != 0) ? "failed\n" : "okay\n";
  }

  return result;
}