bool Shell(int *fd_stdin, int *fd_stdout, int *fd_stderr) {
  const bool double_fork = true;
  return ExecuteBinary(fd_stdin, fd_stdout, fd_stderr, "/bin/sh",
                       vector<string>(), double_fork);
}