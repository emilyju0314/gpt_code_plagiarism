void CacheAccessor::lookUpInShaderCaches(MetroHash::Hash &hash) {
  ShaderCache *applicationCache = static_cast<ShaderCache *>(getApplicationShaderCache());
  ShaderCache *internalCache = static_cast<ShaderCache *>(getInternalShaderCache());
  bool usingApplicationCache = applicationCache && cl::ShaderCacheMode != ShaderCacheForceInternalCacheOnDisk;
  if (internalCache) {
    if (lookUpInShaderCache(hash, !usingApplicationCache, internalCache))
      return;
  }
  if (usingApplicationCache) {
    if (lookUpInShaderCache(hash, true, applicationCache))
      return;
  }
  resetShaderCacheTrackingData();
}