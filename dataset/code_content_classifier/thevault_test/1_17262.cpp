void CacheAccessor::updateShaderCache(BinaryData &elf) {
  ShaderCache *shaderCache = m_shaderCache;
  if (!m_shaderCacheEntry)
    return;

  if (!shaderCache)
    shaderCache = static_cast<ShaderCache *>(getInternalShaderCache());

  if (elf.pCode) {
    assert(elf.codeSize > 0);
    shaderCache->insertShader(m_shaderCacheEntry, elf.pCode, elf.codeSize);
  } else
    shaderCache->resetShader(m_shaderCacheEntry);
}