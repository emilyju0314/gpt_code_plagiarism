SystemInfo::SystemInfo()
    : physical_cpus_(1), logical_cpus_(1), cache_size_(0),
      cpu_family_(0), cpu_model_(0), cpu_stepping_(0),
      cpu_speed_(0), memory_(0) {
  // Initialize the basic information.
#if defined(__arm__) || defined(_M_ARM)
  cpu_arch_ = SI_ARCH_ARM;
#elif defined(__x86_64__) || defined(_M_X64)
  cpu_arch_ = SI_ARCH_X64;
#elif defined(__i386__) || defined(_M_IX86)
  cpu_arch_ = SI_ARCH_X86;
#else
  cpu_arch_ = SI_ARCH_UNKNOWN;
#endif

#if defined(WEBRTC_WIN)
  SYSTEM_INFO si;
  GetSystemInfo(&si);
  logical_cpus_ = si.dwNumberOfProcessors;
  GetProcessorInformation(&physical_cpus_, &cache_size_);
  if (physical_cpus_ <= 0) {
    physical_cpus_ = logical_cpus_;
  }
  cpu_family_ = si.wProcessorLevel;
  cpu_model_ = si.wProcessorRevision >> 8;
  cpu_stepping_ = si.wProcessorRevision & 0xFF;
#elif defined(WEBRTC_MAC)
  uint32_t sysctl_value;
  size_t length = sizeof(sysctl_value);
  if (!sysctlbyname("hw.physicalcpu_max", &sysctl_value, &length, NULL, 0)) {
    physical_cpus_ = static_cast<int>(sysctl_value);
  }
  length = sizeof(sysctl_value);
  if (!sysctlbyname("hw.logicalcpu_max", &sysctl_value, &length, NULL, 0)) {
    logical_cpus_ = static_cast<int>(sysctl_value);
  }
  uint64_t sysctl_value64;
  length = sizeof(sysctl_value64);
  if (!sysctlbyname("hw.l3cachesize", &sysctl_value64, &length, NULL, 0)) {
    cache_size_ = static_cast<int>(sysctl_value64);
  }
  if (!cache_size_) {
    length = sizeof(sysctl_value64);
    if (!sysctlbyname("hw.l2cachesize", &sysctl_value64, &length, NULL, 0)) {
      cache_size_ = static_cast<int>(sysctl_value64);
    }
  }
  length = sizeof(sysctl_value);
  if (!sysctlbyname("machdep.cpu.family", &sysctl_value, &length, NULL, 0)) {
    cpu_family_ = static_cast<int>(sysctl_value);
  }
  length = sizeof(sysctl_value);
  if (!sysctlbyname("machdep.cpu.model", &sysctl_value, &length, NULL, 0)) {
    cpu_model_ = static_cast<int>(sysctl_value);
  }
  length = sizeof(sysctl_value);
  if (!sysctlbyname("machdep.cpu.stepping", &sysctl_value, &length, NULL, 0)) {
    cpu_stepping_ = static_cast<int>(sysctl_value);
  }
#elif defined(__native_client__)
  // TODO(ryanpetrie): Implement this via PPAPI when it's available.
#else  // WEBRTC_LINUX
  ProcCpuInfo proc_info;
  if (proc_info.LoadFromSystem()) {
    proc_info.GetNumCpus(&logical_cpus_);
    proc_info.GetNumPhysicalCpus(&physical_cpus_);
    proc_info.GetCpuFamily(&cpu_family_);
#if defined(CPU_X86)
    // These values only apply to x86 systems.
    proc_info.GetSectionIntValue(0, "model", &cpu_model_);
    proc_info.GetSectionIntValue(0, "stepping", &cpu_stepping_);
    proc_info.GetSectionIntValue(0, "cpu MHz", &cpu_speed_);
    proc_info.GetSectionIntValue(0, "cache size", &cache_size_);
    cache_size_ *= 1024;
#endif
  }
  // ProcCpuInfo reads cpu speed from "cpu MHz" under /proc/cpuinfo.
  // But that number is a moving target which can change on-the-fly according to
  // many factors including system workload.
  // See /sys/devices/system/cpu/cpu0/cpufreq/scaling_available_governors.
  // The one in /sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_max_freq is more
  // accurate. We use it as our cpu speed when it is available.
  // cpuinfo_max_freq is measured in KHz and requires conversion to MHz.
  int max_freq = rtc::ReadCpuMaxFreq();
  if (max_freq > 0) {
    cpu_speed_ = max_freq / 1000;
  }
#endif
// For L2 CacheSize see also
// http://www.flounder.com/cpuid_explorer2.htm#CPUID(0x800000006)
#ifdef CPU_X86
  if (cache_size_ == 0) {
    int cpu_info[4];
    __cpuid(cpu_info, 0x80000000);  // query maximum extended cpuid function.
    if (static_cast<uint32>(cpu_info[0]) >= 0x80000006) {
      __cpuid(cpu_info, 0x80000006);
      cache_size_ = (cpu_info[2] >> 16) * 1024;
    }
  }
#endif
}