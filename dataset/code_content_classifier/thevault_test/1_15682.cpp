static void enforce_mem_limit() {
      if (!sqlite_mem_enforced) {
         sqlite3_soft_heap_limit(SQLITE_THREAD_MEM*1024*1024);
         sqlite_mem_enforced = true;
      }
   }