void *SqliteMemoryManager::MallocArena::Malloc(const uint32_t size) {
  assert(size > 0);

  // Control word first, block type tag last
  int32_t total_size = sizeof(ReservedBlockCtl) + size + 1;
  total_size = RoundUp8(total_size);
  if (total_size < kMinBlockSize)
    total_size = kMinBlockSize;

  AvailBlockCtl *p = FindAvailBlock(total_size);
  if (p == NULL)
    return NULL;

  no_reserved_++;
  return ReserveBlock(p, total_size);
}