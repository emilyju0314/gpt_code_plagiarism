SqliteMemoryManager::~SqliteMemoryManager() {
  if (assigned_) {
    // Reset sqlite to default values
    int retval;
    retval = sqlite3_config(SQLITE_CONFIG_SCRATCH, NULL, 0, 0);
    assert(retval == SQLITE_OK);
    retval = sqlite3_config(SQLITE_CONFIG_PAGECACHE, NULL, 0, 0);
    assert(retval == SQLITE_OK);
    retval = sqlite3_config(SQLITE_CONFIG_MALLOC, &sqlite3_mem_vanilla_);
    assert(retval == SQLITE_OK);
  }

  sxunmap(scratch_memory_, kScratchSize);
  sxunmap(page_cache_memory_, kPageCacheSize);
  for (unsigned i = 0; i < lookaside_buffer_arenas_.size(); ++i)
    delete lookaside_buffer_arenas_[i];
  for (unsigned i = 0; i < malloc_arenas_.size(); ++i)
    delete malloc_arenas_[i];
  pthread_mutex_destroy(&lock_);
}