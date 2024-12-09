static void enforce_mem_limit() {
    if (!getMemoryEnforcedFlag()) {
      sqlite3_soft_heap_limit(SQLITE_THREAD_MEM*1024*1024);
      setMemoryEnforcedFlag(true);
    }
  }