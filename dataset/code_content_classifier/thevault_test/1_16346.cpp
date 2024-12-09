SqliteMemoryManager::MallocArena::AvailBlockCtl *
SqliteMemoryManager::MallocArena::FindAvailBlock(const int32_t block_size) {
  bool wrapped = false;
  // Generally: p = LINK(q)
  AvailBlockCtl *q = rover_;
  AvailBlockCtl *p;
  do {
    p = q->GetNextPtr(arena_);
    if (p->size >= block_size) {
      rover_ = p->GetNextPtr(arena_);
      return p;
    }
    if (p == head_avail_) {
      if (wrapped)
        return NULL;
      wrapped = true;
    }
    q = p;
  } while (true);
}