int SystemInfo::GetMaxCpuSpeed() {
  if (cpu_speed_) {
    return cpu_speed_;
  }
#if defined(WEBRTC_WIN)
  HKEY key;
  static const WCHAR keyName[] =
      L"HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0";

  if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, keyName , 0, KEY_QUERY_VALUE, &key)
      == ERROR_SUCCESS) {
    DWORD data, len;
    len = sizeof(data);

    if (RegQueryValueEx(key, L"~Mhz", 0, 0, reinterpret_cast<LPBYTE>(&data),
                        &len) == ERROR_SUCCESS) {
      cpu_speed_ = data;
    } else {
      LOG(LS_WARNING) << "Failed to query registry value HKLM\\" << keyName
                      << "\\~Mhz";
      cpu_speed_ = -1;
    }

    RegCloseKey(key);
  } else {
    LOG(LS_WARNING) << "Failed to open registry key HKLM\\" << keyName;
    cpu_speed_ = -1;
  }
#elif defined(WEBRTC_MAC)
  uint64_t sysctl_value;
  size_t length = sizeof(sysctl_value);
  int error = sysctlbyname("hw.cpufrequency_max", &sysctl_value, &length,
                           NULL, 0);
  cpu_speed_ = !error ? static_cast<int>(sysctl_value/1000000) : -1;
#else
  // TODO(fbarchard): Implement using proc/cpuinfo
  cpu_speed_ = 0;
#endif
  return cpu_speed_;
}