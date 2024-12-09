void
inode_manager::write_file(uint32_t inum, const char *buf, int size)
{
  /*
   * your lab1 code goes here.
   * note: write buf to blocks of inode inum.
   * you need to consider the situation when the size of buf 
   * is larger or smaller than the size of original inode
   */

  printf("\tim: write_file %d, size %d\n", inum, size);

  if (inum >= INODE_NUM) return;
  
  int nblocks = bm->get_nblocks(size);

  if (nblocks > MAXFILE) return;

  struct inode *inode = get_inode(inum);
  
  int old_nblocks = bm->get_nblocks(inode->size);

  inode->size = size;

  blockid_t indirect_blocks[NINDIRECT];
  
  if (old_nblocks > NDIRECT) {
        bm->read_block(inode->blocks[NDIRECT], (char *)indirect_blocks);
  }
  if (nblocks > old_nblocks) {
    // grow
    int i = old_nblocks;
    if (old_nblocks < NDIRECT) {
      for (; i < MIN(NDIRECT, nblocks); ++i) {
        inode->blocks[i] = bm->alloc_block();
      }
    }
    if (i < nblocks) {
      
      // need to alloc indirect blocks
      if (old_nblocks <= NDIRECT) {
        inode->blocks[NDIRECT] = bm->alloc_block();
      } else {
        i = old_nblocks; // ASSERT old_nblocks > DIRECT
      }

      for (; i < nblocks; ++i) {
        indirect_blocks[i - NDIRECT] = bm->alloc_block();
      }

      bm->write_block(inode->blocks[NDIRECT], (const char *)indirect_blocks);
    }
  } else if (nblocks < old_nblocks) {
    // shrink
    int i;

    for (i = old_nblocks - 1; i >= MAX(NDIRECT, nblocks); --i) {
      blockid_t id = indirect_blocks[i - NDIRECT];
      bm->free_block(id);
    }
    
    if (i >= nblocks) {
      if (old_nblocks > NDIRECT)  
        bm->free_block(inode->blocks[NDIRECT]);
      for (; i >= nblocks; --i) {
        blockid_t id = inode->blocks[i];
        bm->free_block(id);
      }
    }
  }

  // copy data
  int i = 0;
  char write_buf[BLOCK_SIZE];

  for (; i < MIN(nblocks, NDIRECT); ++i) {
    blockid_t id = inode->blocks[i];
    memset(write_buf, 0, BLOCK_SIZE);
    auto len = MIN(BLOCK_SIZE, size - i * BLOCK_SIZE);
    memcpy(write_buf, buf + i * BLOCK_SIZE, len);
    bm->write_block(id, write_buf);
  }

  for (; i < nblocks; ++i) {
    blockid_t id = indirect_blocks[i - NDIRECT];
    memset(write_buf, 0, BLOCK_SIZE);
    auto len = MIN(BLOCK_SIZE, size - i * BLOCK_SIZE);
    memcpy(write_buf, buf + i * BLOCK_SIZE, len);
    bm->write_block(id, write_buf);
  }  
    
  inode->ctime = inode->mtime = inode->atime = std::time(0);
  put_inode(inum, inode);

  free(inode);
  
}