int64 SystemInfo::GetMemorySize() {
  if (memory_) {
    return memory_;
  }

#if defined(WEBRTC_WIN)
  MEMORYSTATUSEX status = {0};
  status.dwLength = sizeof(status);

  if (GlobalMemoryStatusEx(&status)) {
    memory_ = status.ullTotalPhys;
  } else {
    LOG_GLE(LS_WARNING) << "GlobalMemoryStatusEx failed.";
    memory_ = -1;
  }

#elif defined(WEBRTC_MAC)
  size_t len = sizeof(memory_);
  int error = sysctlbyname("hw.memsize", &memory_, &len, NULL, 0);
  if (error || memory_ == 0) {
    memory_ = -1;
  }
#else  // WEBRTC_LINUX
  memory_ = static_cast<int64>(sysconf(_SC_PHYS_PAGES)) *
      static_cast<int64>(sysconf(_SC_PAGESIZE));
  if (memory_ < 0) {
    LOG(LS_WARNING) << "sysconf(_SC_PHYS_PAGES) failed."
                    << "sysconf(_SC_PHYS_PAGES) " << sysconf(_SC_PHYS_PAGES)
                    << "sysconf(_SC_PAGESIZE) " << sysconf(_SC_PAGESIZE);
    memory_ = -1;
  }
#endif

  return memory_;
}