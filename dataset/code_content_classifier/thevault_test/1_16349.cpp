uint32_t SqliteMemoryManager::MallocArena::GetSize(void *ptr) const {
  assert(Contains(ptr));

  ReservedBlockCtl *block_ctl = reinterpret_cast<ReservedBlockCtl *>(
    reinterpret_cast<char *>(ptr) - sizeof(ReservedBlockCtl));
  int32_t size = block_ctl->size();
  assert(size > 1);
  return size - sizeof(ReservedBlockCtl) - 1;
}