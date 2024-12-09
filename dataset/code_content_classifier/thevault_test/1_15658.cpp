int SystemInfo::GetCurCpuSpeed() {
#if defined(WEBRTC_WIN)
  // TODO(fbarchard): Add WMI check, requires COM initialization
  // NOTE(fbarchard): Testable on Sandy Bridge.
  return GetMaxCpuSpeed();
#elif defined(WEBRTC_MAC)
  uint64_t sysctl_value;
  size_t length = sizeof(sysctl_value);
  int error = sysctlbyname("hw.cpufrequency", &sysctl_value, &length, NULL, 0);
  return !error ? static_cast<int>(sysctl_value/1000000) : GetMaxCpuSpeed();
#else  // WEBRTC_LINUX
  // TODO(fbarchard): Use proc/cpuinfo for Cur speed on Linux.
  return GetMaxCpuSpeed();
#endif
}