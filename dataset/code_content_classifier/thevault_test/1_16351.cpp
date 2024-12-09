SqliteMemoryManager::MallocArena::MallocArena()
  : arena_(reinterpret_cast<char *>(sxmmap_align(kArenaSize)))
  , head_avail_(reinterpret_cast<AvailBlockCtl *>(arena_ + sizeof(uint64_t)))
  , rover_(head_avail_)
  , no_reserved_(0)
{
  const unsigned char padding = 7;
  // Size of the initial free block: everything minus arena boundaries
  int32_t usable_size = kArenaSize -
    (sizeof(uint64_t) + sizeof(AvailBlockCtl) + padding + 1 + sizeof(int32_t));
  assert((usable_size % 8) == 0);

  // First 8 bytes of arena: this pointer (occupies only 4 bytes on 32bit
  // architectures, in which case the second 4 bytes are unused.)
  *reinterpret_cast<MallocArena **>(arena_) = this;

  // The initial large free block
  AvailBlockCtl *free_block =
    new (arena_ + sizeof(uint64_t) + sizeof(AvailBlockCtl) + padding + 1)
    AvailBlockCtl();
  free_block->size = usable_size;
  free_block->link_next = free_block->link_prev =
    head_avail_->ConvertToLink(arena_);
  new (AvailBlockTag::GetTagLocation(free_block)) AvailBlockTag(usable_size);

  head_avail_->size = 0;
  head_avail_->link_next = head_avail_->link_prev =
    free_block->ConvertToLink(arena_);

  // Prevent succeeding blocks from merging
  *(reinterpret_cast<char *>(free_block) - 1) = kTagReserved;
  // Final tag: reserved block marker
  *reinterpret_cast<int32_t *>(arena_ + kArenaSize - sizeof(int32_t)) = -1;
}