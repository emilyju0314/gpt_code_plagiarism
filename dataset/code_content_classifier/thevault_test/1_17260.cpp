bool CacheAccessor::lookUpInShaderCache(const MetroHash::Hash &hash, bool allocateOnMiss, ShaderCache *cache) {
  CacheEntryHandle currentEntry;
  ShaderEntryState cacheEntryState = cache->findShader(hash, allocateOnMiss, &currentEntry);
  if (cacheEntryState == ShaderEntryState::Ready) {
    Result result = cache->retrieveShader(currentEntry, &m_elf.pCode, &m_elf.codeSize);
    if (result == Result::Success) {
      m_shaderCacheEntryState = ShaderEntryState::Ready;
      return true;
    }
  } else if (cacheEntryState == ShaderEntryState::Compiling) {
    m_shaderCache = cache;
    m_shaderCacheEntry = currentEntry;
    m_shaderCacheEntryState = ShaderEntryState::Compiling;
    return true;
  }
  return false;
}