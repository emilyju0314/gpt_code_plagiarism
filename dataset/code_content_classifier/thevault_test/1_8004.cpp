static void sigLog(const int sig)
{
  syslog(LOG_ERR, "%s - got %d\n", __func__, sig);
  stacktrace_logger(sig);
  exit(EXIT_FAILURE);
}