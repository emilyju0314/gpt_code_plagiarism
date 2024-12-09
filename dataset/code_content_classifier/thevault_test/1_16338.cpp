bool ManagedExec(const vector<string>  &command_line,
                 const set<int>        &preserve_fildes,
                 const map<int, int>   &map_fildes,
                 const bool             drop_credentials,
                 const bool             double_fork,
                       pid_t           *child_pid)
{
  assert(command_line.size() >= 1);

  Pipe pipe_fork;
  pid_t pid = fork();
  assert(pid >= 0);
  if (pid == 0) {
    pid_t pid_grand_child;
    int max_fd;
    int fd_flags;
    ForkFailures::Names failed = ForkFailures::kUnknown;

    const char *argv[command_line.size() + 1];
    for (unsigned i = 0; i < command_line.size(); ++i)
      argv[i] = command_line[i].c_str();
    argv[command_line.size()] = NULL;

    // Child, map file descriptors
    for (map<int, int>::const_iterator i = map_fildes.begin(),
         iEnd = map_fildes.end(); i != iEnd; ++i)
    {
      int retval = dup2(i->first, i->second);
      if (retval == -1) {
        failed = ForkFailures::kFailDupFd;
        goto fork_failure;
      }
    }

    // Child, close file descriptors
    max_fd = sysconf(_SC_OPEN_MAX);
    if (max_fd < 0) {
      failed = ForkFailures::kFailGetMaxFd;
      goto fork_failure;
    }
    for (int fd = 0; fd < max_fd; fd++) {
      if ((fd != pipe_fork.write_end) && (preserve_fildes.count(fd) == 0)) {
        close(fd);
      }
    }

    // Double fork to disconnect from parent
    if (double_fork) {
      pid_grand_child = fork();
      assert(pid_grand_child >= 0);
      if (pid_grand_child != 0) _exit(0);
    }

    fd_flags = fcntl(pipe_fork.write_end, F_GETFD);
    if (fd_flags < 0) {
      failed = ForkFailures::kFailGetFdFlags;
      goto fork_failure;
    }
    fd_flags |= FD_CLOEXEC;
    if (fcntl(pipe_fork.write_end, F_SETFD, fd_flags) < 0) {
      failed = ForkFailures::kFailSetFdFlags;
      goto fork_failure;
    }

#ifdef DEBUGMSG
    assert(setenv("__CVMFS_DEBUG_MODE__", "yes", 1) == 0);
#endif
    if (drop_credentials && !SwitchCredentials(geteuid(), getegid(), false)) {
      failed = ForkFailures::kFailDropCredentials;
      goto fork_failure;
    }

    // retrieve the PID of the new (grand) child process and send it to the
    // grand father
    pid_grand_child = getpid();
    pipe_fork.Write(ForkFailures::kSendPid);
    pipe_fork.Write(pid_grand_child);

    execvp(command_line[0].c_str(), const_cast<char **>(argv));

    failed = ForkFailures::kFailExec;

   fork_failure:
    pipe_fork.Write(failed);
    _exit(1);
  }
  if (double_fork) {
    int statloc;
    waitpid(pid, &statloc, 0);
  }

  close(pipe_fork.write_end);

  // Either the PID or a return value is sent
  ForkFailures::Names status_code;
  bool retcode = pipe_fork.Read(&status_code);
  assert(retcode);
  if (status_code != ForkFailures::kSendPid) {
    close(pipe_fork.read_end);
    LogCvmfs(kLogCvmfs, kLogDebug, "managed execve failed (%s)",
             ForkFailures::ToString(status_code).c_str());
    return false;
  }

  // read the PID of the spawned process if requested
  // (the actual read needs to be done in any case!)
  pid_t buf_child_pid = 0;
  retcode = pipe_fork.Read(&buf_child_pid);
  assert(retcode);
  if (child_pid != NULL)
    *child_pid = buf_child_pid;
  close(pipe_fork.read_end);
  LogCvmfs(kLogCvmfs, kLogDebug, "execve'd %s (PID: %d)",
           command_line[0].c_str(),
           static_cast<int>(buf_child_pid));
  return true;
}