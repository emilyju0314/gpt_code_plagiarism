std::unique_ptr<ProfilerInterface> CreateHostTracer(
    const ProfileOptions& options) {
  if (options.host_tracer_level() == 0) return nullptr;
  return absl::make_unique<HostTracer>(options.host_tracer_level());
}