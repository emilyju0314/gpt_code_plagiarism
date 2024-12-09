void mld_register_alloc(void *ptr, size_t size)
{
  void *backtrace;
  unsigned short frames;
  unsigned long hash;

  if (pAllocMgr == NULL)
  {
    void *alloc_mgr_ptr = malloc(sizeof(HeapAllocManager));
    if (alloc_mgr_ptr == NULL) 
    {
      throw std::bad_alloc();
    }
    pAllocMgr = new (alloc_mgr_ptr) HeapAllocManager();
  }

  captureStackBackTrace(3, &backtrace, frames, &hash);
  pAllocMgr->register_alloc(ptr, size, &backtrace, frames, hash);
}