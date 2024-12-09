void SqliteMemoryManager::MallocArena::UnlinkAvailBlock(AvailBlockCtl *block) {
  AvailBlockCtl *next = block->GetNextPtr(arena_);
  AvailBlockCtl *prev = block->GetPrevPtr(arena_);
  prev->link_next = block->link_next;
  next->link_prev = block->link_prev;
}