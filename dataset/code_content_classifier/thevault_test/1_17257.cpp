Result CacheAccessor::lookUpInCache(Vkgc::ICache *cache, bool allocateOnMiss, const Vkgc::HashId &hashId) {
  Vkgc::EntryHandle currentEntry;
  Result cacheResult = cache->GetEntry(hashId, allocateOnMiss, &currentEntry);

  if (cacheResult == Result::NotReady)
    cacheResult = currentEntry.WaitForEntry();

  if (cacheResult == Result::Success) {
    cacheResult = currentEntry.GetValueZeroCopy(&m_elf.pCode, &m_elf.codeSize);
    m_cacheEntry = std::move(currentEntry);
  } else if (allocateOnMiss && (cacheResult == Result::NotFound)) {
    m_cacheEntry = std::move(currentEntry);
  }
  return cacheResult;
}