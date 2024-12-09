void
inode_manager::read_file(uint32_t inum, char **buf_out, int *size)
{
  /*
   * your lab1 code goes here.
   * note: read blocks related to inode number inum,
   * and copy them to buf_Out
   */
  if (inum >= INODE_NUM) return;

  struct inode *ino = get_inode(inum);
  *size = ino->size;
  
  int i;
  int nblocks = bm->get_nblocks(ino->size); 
  *buf_out = (char *)malloc(nblocks * BLOCK_SIZE);

  for (i = 0; i < MIN(NDIRECT, nblocks); i++) {
    blockid_t id = ino->blocks[i];
    bm->read_block(id, *buf_out + i * BLOCK_SIZE);
  }

  if (i < nblocks) {

    blockid_t indirect_blocks[NINDIRECT];
    bm->read_block(ino->blocks[NDIRECT], (char *)indirect_blocks);

    for (; i < nblocks; ++i) {
      blockid_t id = indirect_blocks[i - NDIRECT];
      bm->read_block(id, *buf_out + i * BLOCK_SIZE);
    }

  }
  
  ino->atime = std::time(0);
  put_inode(inum, ino);

  free(ino);
}