folly::Optional<size_t>
SystemMetrics::getRSSMemBytes() {
#if !defined(IS_BSD)
  folly::Optional<size_t> rss{folly::none};
  // match the line like: "VmRSS:      9028 kB"
  std::regex rssRegex("VmRSS:\\s+(\\d+)\\s+(\\w+)");
  std::smatch rssMatched;
  std::string line;
  std::ifstream input;
  try {
    // "/proc/self/" allows a process to look at itself without knowing the PID.
    std::ifstream input("/proc/self/status");
    if (input.is_open()) {
      while (std::getline(input, line)) {
        if (std::regex_search(line, rssMatched, rssRegex) &&
            rssMatched[2] == "kB") {
          rss = std::stoull(rssMatched[1]) * 1024;
          break;
        }
      }
    }
  } catch (const std::exception& ex) {
    LOG(ERROR)
        << "Fail to read the \"/proc/self/status\" of current process to get the memory usage: "
        << ex.what();
  }
  return rss;
#elif !defined(__APPLE__)
  struct rusage rusage;
  getrusage(RUSAGE_SELF, &rusage);
  return (size_t)(rusage.ru_maxrss * 1024);
#else
  struct task_basic_info t_info;
  mach_msg_type_number_t t_info_count = TASK_BASIC_INFO_COUNT;
  task_info(
      current_task(), TASK_BASIC_INFO, (task_info_t)&t_info, &t_info_count);
  return t_info.resident_size;
#endif
}