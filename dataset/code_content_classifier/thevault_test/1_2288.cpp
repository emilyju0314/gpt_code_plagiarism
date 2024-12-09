uint32_t GetWatchpointWriteFlag(debug_ipc::BreakpointType type) {
  // clang-format off
  switch (type) {
    case debug_ipc::BreakpointType::kRead: return 0b01;
    case debug_ipc::BreakpointType::kReadWrite: return 0b11;
    case debug_ipc::BreakpointType::kWrite: return 0b10;
    case debug_ipc::BreakpointType::kSoftware:
    case debug_ipc::BreakpointType::kHardware:
    case debug_ipc::BreakpointType::kLast:
      break;
  }
  // clang-format on

  FXL_NOTREACHED() << "Invalid breakpoint type: " << static_cast<uint32_t>(type);
  return 0;
}