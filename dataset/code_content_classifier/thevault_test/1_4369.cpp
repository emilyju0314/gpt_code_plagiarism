bool mld_deregister_alloc(void *ptr)
{
  bool success = true;
  if (!pAllocMgr->deregister_alloc(ptr))
  {
    // The ptr was not in the allocation table
    void *backtrace;
    unsigned short frames;
    unsigned long hash;
    captureStackBackTrace(2, &backtrace, frames, &hash);
    pAllocMgr->dumpStackTrace(&backtrace, frames);
    success = false;
  }
  return success;
}