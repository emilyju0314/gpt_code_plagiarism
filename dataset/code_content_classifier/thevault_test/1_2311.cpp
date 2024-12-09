zx::unowned_profile GetProfile(int priority, std::optional<zx_cpu_set_t> affinity) {
  using Key = std::tuple<int, std::optional<zx_cpu_set_t>>;
  const Key key{priority, affinity};

  // Maintains a map of profiles for each previously requested priority/affinity.
  static std::map<Key, zx::profile> profiles;
  static std::mutex mutex;

  std::lock_guard<std::mutex> guard{mutex};

  // Return the existing handle if it's already in the map.
  auto search = profiles.find(key);
  if (search != profiles.end()) {
    return zx::unowned_profile{search->second.get()};
  }

  auto& provider = GetProfileProvider();

  zx_status_t fidl_status;
  zx::profile profile;
  const auto status = provider.GetProfile(priority, "garnet/bin/loadbench", &fidl_status, &profile);
  FXL_CHECK(status == ZX_OK);
  FXL_CHECK(fidl_status == ZX_OK);

  // Add the new profile to the map for later retrieval.
  auto [iter, okay] = profiles.emplace(key, std::move(profile));
  FXL_CHECK(okay);

  return zx::unowned_profile{iter->second.get()};
}