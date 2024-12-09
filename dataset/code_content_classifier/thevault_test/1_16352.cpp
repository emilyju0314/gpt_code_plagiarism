SqliteMemoryManager::MallocArena *
SqliteMemoryManager::MallocArena::CreateInitialized(
  unsigned char pattern)
{
  MallocArena *result = new MallocArena();
  // At this point, there is one big free block linked to by head_avail_
  AvailBlockCtl *free_block = result->head_avail_->GetNextPtr(result->arena_);
  assert(free_block != result->head_avail_);
  assert(free_block->size > 0);
  // Strip control information at both ends of the block
  int usable_size = free_block->size -
                    (sizeof(AvailBlockCtl) + sizeof(AvailBlockTag));
  assert(usable_size > 0);
  memset(free_block + 1, pattern, usable_size);
  return result;
}