void *SqliteMemoryManager::MallocArena::ReserveBlock(
  AvailBlockCtl *block,
  int32_t block_size)
{
  assert(block->size >= block_size);

  int32_t remaining_size = block->size - block_size;
  // Avoid creation of very small blocks
  if (remaining_size < kMinBlockSize) {
    block_size += remaining_size;
    remaining_size = 0;
  }

  // Update the list of available blocks
  if (remaining_size == 0) {
    // Remove free block p from the list of available blocks
    UnlinkAvailBlock(block);
  } else {
    block->ShrinkTo(remaining_size);
  }

  // Place the new allocation, which also sets the block type tag at the end
  char *new_block = reinterpret_cast<char *>(block) + remaining_size;
  new (new_block) ReservedBlockCtl(block_size);
  return new_block + sizeof(ReservedBlockCtl);
}