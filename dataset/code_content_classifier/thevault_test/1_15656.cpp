std::string SystemInfo::GetCpuVendor() {
  if (cpu_vendor_.empty()) {
#if defined(CPU_X86)
    int cpu_info[4];
    __cpuid(cpu_info, 0);
    cpu_info[0] = cpu_info[1];  // Reorder output
    cpu_info[1] = cpu_info[3];
    // cpu_info[2] = cpu_info[2];  // Avoid -Werror=self-assign
    cpu_info[3] = 0;
    cpu_vendor_ = std::string(reinterpret_cast<char*>(&cpu_info[0]));
#elif defined(CPU_ARM)
    cpu_vendor_ = std::string("ARM");
#else
    cpu_vendor_ = std::string("Undefined");
#endif
  }
  return cpu_vendor_;
}