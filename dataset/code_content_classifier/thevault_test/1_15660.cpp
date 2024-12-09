std::string SystemInfo::GetMachineModel() {
  if (!machine_model_.empty()) {
    return machine_model_;
  }

#if defined(WEBRTC_MAC)
  char buffer[128];
  size_t length = sizeof(buffer);
  int error = sysctlbyname("hw.model", buffer, &length, NULL, 0);
  if (!error) {
    machine_model_.assign(buffer, length - 1);
  } else {
    machine_model_.clear();
  }
#else
  machine_model_ = "Not available";
#endif

  return machine_model_;
}