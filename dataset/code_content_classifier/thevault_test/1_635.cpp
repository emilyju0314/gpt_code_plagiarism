static int check_addr(void* addr) {
  if (addr > g_mempool.start_addr && addr < g_mempool.start_addr + g_mempool.total_size) {
    return 1;
  }
  return -1;
}