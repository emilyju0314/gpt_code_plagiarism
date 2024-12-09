void SqliteMemoryManager::MallocArena::Free(void *ptr) {
  assert(Contains(ptr));

  no_reserved_--;

  ReservedBlockCtl *block_ctl = reinterpret_cast<ReservedBlockCtl *>(
    reinterpret_cast<char *>(ptr) - sizeof(ReservedBlockCtl));
  char prior_tag = *(reinterpret_cast<char *>(block_ctl) - 1);
  assert((prior_tag == kTagAvail) || (prior_tag == kTagReserved));

  int32_t new_size = block_ctl->size();
  assert(new_size > 0);
  AvailBlockCtl *new_avail = reinterpret_cast<AvailBlockCtl *>(block_ctl);

  if (prior_tag == kTagAvail) {
    // Merge with block before and remove the block from the list
    int32_t prior_size = reinterpret_cast<AvailBlockTag *>(
      reinterpret_cast<char *>(block_ctl) - sizeof(AvailBlockTag))->size;
    assert(prior_size > 0);
    new_size += prior_size;
    new_avail = reinterpret_cast<AvailBlockCtl *>(
      reinterpret_cast<char *>(block_ctl) - prior_size);
    // new_avail points now to the prior block
    UnlinkAvailBlock(new_avail);
    if (rover_ == new_avail)
      rover_ = head_avail_;
  }

  int32_t succ_size = *reinterpret_cast<int32_t *>(
    reinterpret_cast<char *>(new_avail) + new_size);
  if (succ_size >= 0) {
    // Merge with succeeding block and remove the block from the list
    AvailBlockCtl *succ_avail = reinterpret_cast<AvailBlockCtl *>(
      reinterpret_cast<char *>(new_avail) + new_size);
    UnlinkAvailBlock(succ_avail);
    new_size += succ_size;
    if (rover_ == succ_avail)
      rover_ = head_avail_;
  }

  // Set new free block's boundaries
  new_avail->size = new_size;
  new (AvailBlockTag::GetTagLocation(new_avail)) AvailBlockTag(new_size);

  EnqueueAvailBlock(new_avail);
}