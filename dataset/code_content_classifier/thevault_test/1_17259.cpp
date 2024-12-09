void CacheAccessor::resetShaderCacheTrackingData() {
  m_shaderCache = nullptr;
  m_shaderCacheEntry = nullptr;
  m_shaderCacheEntryState = ShaderEntryState::New;
}