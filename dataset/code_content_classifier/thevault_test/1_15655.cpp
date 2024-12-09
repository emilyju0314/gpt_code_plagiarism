int SystemInfo::GetCurCpus() {
  int cur_cpus;
#if defined(WEBRTC_WIN)
  DWORD_PTR process_mask, system_mask;
  ::GetProcessAffinityMask(::GetCurrentProcess(), &process_mask, &system_mask);
  for (cur_cpus = 0; process_mask; ++cur_cpus) {
    // Sparse-ones algorithm. There are slightly faster methods out there but
    // they are unintuitive and won't make a difference on a single dword.
    process_mask &= (process_mask - 1);
  }
#elif defined(WEBRTC_MAC)
  uint32_t sysctl_value;
  size_t length = sizeof(sysctl_value);
  int error = sysctlbyname("hw.ncpu", &sysctl_value, &length, NULL, 0);
  cur_cpus = !error ? static_cast<int>(sysctl_value) : 1;
#else
  // Linux, Solaris, WEBRTC_ANDROID
  cur_cpus = static_cast<int>(sysconf(_SC_NPROCESSORS_ONLN));
#endif
  return cur_cpus;
}