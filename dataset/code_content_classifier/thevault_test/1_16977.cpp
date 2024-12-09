void ResizeMapping(const ScopedAnonymousMmap& mapping, size_t load_size) {
  // Trim the reservation mapping to match the library's actual size. Failure
  // to resize is not a fatal error. At worst we lose a portion of virtual
  // address space that we might otherwise have recovered. Note that trimming
  // the mapping here requires that we have already released the scoped
  // mapping.
  const uintptr_t uintptr_addr = reinterpret_cast<uintptr_t>(mapping.address());
  if (mapping.size() <= load_size) {
    LOG_ERROR("WARNING: library reservation was too small");
  } else {
    // Unmap the part of the reserved address space that is beyond the end of
    // the loaded library data.
    void* unmap = reinterpret_cast<void*>(uintptr_addr + load_size);
    const size_t length = mapping.size() - load_size;
    munmap(unmap, length);
  }
}