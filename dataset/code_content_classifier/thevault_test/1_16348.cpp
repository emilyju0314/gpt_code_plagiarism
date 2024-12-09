void SqliteMemoryManager::MallocArena::EnqueueAvailBlock(AvailBlockCtl *block) {
  AvailBlockCtl *next = head_avail_;
  AvailBlockCtl *prev = head_avail_->GetPrevPtr(arena_);
  next->link_prev = block->ConvertToLink(arena_);
  prev->link_next = block->ConvertToLink(arena_);
  block->link_next = head_avail_->ConvertToLink(arena_);
  block->link_prev = prev->ConvertToLink(arena_);
}