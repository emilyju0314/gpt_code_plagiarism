blockid_t
block_manager::alloc_block()
{
  /*
   * your lab1 code goes here.
   * note: you should mark the corresponding bit in block bitmap when alloc.
   * you need to think about which block you can start to be allocated.
   */
  
  std::lock_guard<std::mutex> lock(mtx_);
  char bitmap_buf[BLOCK_SIZE];

  for (blockid_t block = IBLOCK(INODE_NUM + 1, BLOCK_NUM), bitmap = BBLOCK(0);
       block < BLOCK_NUM;
       ++bitmap, block += BPB) { 
    read_block(bitmap, bitmap_buf);
    
    for (uint32_t byte_index = 0; byte_index < BLOCK_SIZE; ++byte_index) {
      unsigned char byte = bitmap_buf[byte_index]; 

      for (unsigned char bit_index = 0; bit_index < 8; ++bit_index) {

        if (!(byte & (1 << bit_index))) {// found available block
          bitmap_buf[byte_index] |= 1 << bit_index;
          write_block(bitmap, bitmap_buf);
         
          blockid_t id = block + byte_index * 8 + bit_index;
          printf("\t\tbm: alloc block %d\n", id);
          return id;
        }
      }
    }
  }
  
  return BLOCK_NUM;

}