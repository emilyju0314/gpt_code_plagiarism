absl::optional<int64> GetKernelEventType(bool is_host_plane,
                                         const XPlaneVisitor& visitor,
                                         const XEvent& event) {
  for (const auto& stat : event.stats()) {
    if (visitor.GetStatType(stat) == StatType::kCorrelationId) {
      return is_host_plane ? HostEventType::kKernelLaunch
                           : HostEventType::kKernelExecute;
    }
  }
  return absl::nullopt;
}