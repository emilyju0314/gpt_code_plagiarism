void LogLine(LogLevel level, const char* filename, int line,
             const std::string& message) {
  if (g_logging_options->alsologtostderr || g_log_file != nullptr) {
    // Filename always has Unix path separators, so this works on Windows, too.
    const char* basename = strrchr(filename, '/');
    if (*basename != '\0') {
      ++basename;
    }

    // Prepare log line
    std::ostringstream thread_id;
    enum { kThreadIdWidth = 7 };
    thread_id << std::setw(kThreadIdWidth) << std::setfill(' ')
              << std::this_thread::get_id();
    std::string formatted = absl::StrCat(
        LogLevelToCStr(level),
        absl::FormatTime("%m%d %R:%E6S" /* "0125 16:09:42.992535" */,
                         absl::Now(), absl::LocalTimeZone()),
        " ", thread_id.str().substr(0, kThreadIdWidth), " ", basename, ":",
        line, "] ", message, "\n");

    if (g_logging_options->alsologtostderr) {
      fputs(formatted.c_str(), stderr);
      fflush(stderr);
    }
    if (g_log_file) {
      fputs(formatted.c_str(), g_log_file);
      fflush(g_log_file);
    }
  }

  msg("%s\n", message.c_str());
}