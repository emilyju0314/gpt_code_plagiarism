std::string GetNativeGoName(const Type& type) {
  if (type.IsPointer()) {
    return "unsafe.Pointer";
  }
  std::string name = GetGoNameImpl(type);

  // Most of the "normal" implementation is in GetGoNameImpl(), and then we do
  // a few hacks here to make it match the previous output of the Go-written
  // tool that parsed abigen directly.
  // TODO(scottmg|dhobsd): Remove or rationalize these over time.
  if (name == "Duration") return "int64";
  if (name == "Futex") return "int32";
  if (name == "Handle") return "uint32";
  if (name == "Koid") return "uint64";
  if (name == "Paddr") return "uintptr";
  if (name == "Signals") return "uint32";
  if (name == "Status") return "int32";
  if (name == "Ticks") return "int64";
  if (name == "Time") return "int64";
  if (name == "Vaddr") return "uintptr";
  if (name == "Vm_option") return "uint32";
  if (name == "zx_channel_call_args_t") return "uintptr";
  if (name == "zx_clock_t") return "uint32";
  if (name == "zx_handle_disposition_t") return "uintptr";
  if (name == "zx_handle_info_t") return "int";
  if (name == "zx_pci_bar_t") return "uintptr";
  if (name == "zx_pci_init_arg_t") return "uintptr";
  if (name == "zx_pcie_device_info_t") return "uintptr";
  if (name == "zx_port_packet_t") return "int";
  if (name == "zx_profile_info_t") return "int";
  if (name == "zx_rights_t") return "uint32";
  if (name == "zx_smc_parameters_t") return "uintptr";
  if (name == "zx_smc_result_t") return "uintptr";
  if (name == "zx_system_powerctl_arg_t") return "int";
  if (name == "zx_wait_item_t") return "uintptr";
  return name;
}