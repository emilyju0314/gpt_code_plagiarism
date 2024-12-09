void orbit_api_set_enabled(uint64_t address, uint64_t api_version, bool enabled) {
  LOG("%s Orbit API at address %#x, version %u", enabled ? "Enabling" : "Disabling", address,
      api_version);
  if (api_version > kOrbitApiVersion) {
    ERROR(
        "Orbit API version in tracee (%u) is newer than the max supported version (%u). "
        "Some features will be unavailable.",
        api_version, kOrbitApiVersion);
  }

  switch (api_version) {
    case 0: {
      auto* api_v0 = absl::bit_cast<orbit_api_v0*>(address);
      orbit_api_initialize_and_set_enabled(api_v0, &orbit_api_initialize_v0, enabled);
    } break;
    case 1: {
      auto* api_v1 = absl::bit_cast<orbit_api_v1*>(address);
      orbit_api_initialize_and_set_enabled(api_v1, &orbit_api_initialize_v1, enabled);
    } break;
    case 2: {
      auto* api_v2 = absl::bit_cast<orbit_api_v2*>(address);
      orbit_api_initialize_and_set_enabled(api_v2, &orbit_api_initialize_v2, enabled);
    } break;
    default:
      UNREACHABLE();
  }

  // Initialize `LockFreeApiEventProducer` and establish the connection to OrbitService now instead
  // of waiting for the first call to `EnqueueApiEvent`. As it takes some time to establish the
  // connection, `producer.IsCapturing()` would otherwise always be false with at least the first
  // event (but possibly more), causing it to be missed even if it comes a long time after calling
  // `orbit_api_set_enabled`.
  // TODO(b/206359125): The fix involving calling GetCaptureEventProducer() here was removed because
  //  of b/209560448 (we could have interrupted a malloc, which is not re-entrant, so we need to
  //  avoid any memory allocation). Re-add the call once we have a solution to allow re-entrancy.
}