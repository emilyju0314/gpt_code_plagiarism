static string ReportStacktrace() {
  string debug = "--\n";

  int recv_signal;
  if (read(pipe_wd_[0], &recv_signal, sizeof(recv_signal)) <
      int(sizeof(recv_signal)))
  {
    return "failure while reading signal number";
  }
  debug += "Signal: " + StringifyInt(recv_signal);

  int recv_errno;
  if (read(pipe_wd_[0], &recv_errno, sizeof(recv_errno)) <
      int(sizeof(recv_errno)))
  {
    return "failure while reading errno";
  }
  debug += ", errno: " + StringifyInt(errno);

  debug += ", version: " + string(VERSION);

  pid_t pid;
  if (read(pipe_wd_[0], &pid, sizeof(pid_t)) < int(sizeof(pid_t))) {
    return "failure while reading PID";
  }
  debug += ", PID: " + StringifyInt(pid) + "\n";

  debug += "Executable path: " + *exe_path_ + "\n";

  debug += GenerateStackTrace(*exe_path_, pid);

  // give the dying cvmfs client the finishing stroke
  if (kill(pid, SIGKILL) != 0) {
    debug += "Failed to kill cvmfs client! (";
    switch (errno) {
      case EINVAL:
        debug += "invalid signal";
        break;
      case EPERM:
        debug += "permission denied";
        break;
      case ESRCH:
        debug += "no such process";
        break;
      default:
        debug += "unknown error " + StringifyInt(errno);
    }
    debug += ")\n\n";
  }

  return debug;
}