ScopedAnonymousMmap ScopedAnonymousMmap::ReserveAtAddress(void* address,
                                                          size_t size) {
  void* actual_address =
      mmap(address, size, PROT_NONE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  if (actual_address == MAP_FAILED) {
    PLOG_ERROR("mmap");
    return {};
  }

  if (actual_address && actual_address != address) {
    LOG_ERROR("Failed to obtain fixed address for load");
    munmap(actual_address, size);
    return {};
  }

  return {actual_address, size};
}