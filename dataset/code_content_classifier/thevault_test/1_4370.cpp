void mld_dump_leaks()
{
  if (pAllocMgr != NULL)
  {
    pAllocMgr->dump();
  }
}