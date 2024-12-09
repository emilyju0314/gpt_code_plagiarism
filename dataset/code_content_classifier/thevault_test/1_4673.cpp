__attribute__((ms_abi)) void orbit_api_start_wine_v1(const char* name, orbit_api_color color,
                                                     uint64_t group_id, uint64_t caller_address) {
  if (caller_address == kOrbitCallerAddressAuto) {
    caller_address = ORBIT_GET_CALLER_PC();
  }
  orbit_api_start_v1(name, color, group_id, caller_address);
}