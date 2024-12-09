void CacheAccessor::lookUpInCaches(const MetroHash::Hash &hash) {
  Vkgc::HashId hashId = {};
  memcpy(&hashId.bytes, &hash.bytes, sizeof(hash));

  Result cacheResult = Result::Unsupported;
  if (getInternalCache()) {
    cacheResult = lookUpInCache(getInternalCache(), !getApplicationCache(), hashId);
    if (cacheResult == Result::Success)
      m_internalCacheHit = true;
  }
  if (getApplicationCache() && cacheResult != Result::Success)
    cacheResult = lookUpInCache(getApplicationCache(), true, hashId);
  m_cacheResult = cacheResult;
}