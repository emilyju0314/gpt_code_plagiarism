void CacheAccessor::setElfInCache(BinaryData elf) {
  if (m_shaderCacheEntryState == ShaderEntryState::Compiling && m_shaderCacheEntry) {
    updateShaderCache(elf);
    mustSucceed(m_shaderCache->retrieveShader(m_shaderCacheEntry, &m_elf.pCode, &m_elf.codeSize),
                "Failed to retrieve shader");
    m_shaderCacheEntryState = ShaderEntryState::Ready;
  }

  if (!m_cacheEntry.IsEmpty()) {
    m_cacheResult = Result::ErrorUnknown;
    if (elf.pCode) {
      mustSucceed(m_cacheEntry.SetValue(true, elf.pCode, elf.codeSize));
      mustSucceed(m_cacheEntry.GetValueZeroCopy(&m_elf.pCode, &m_elf.codeSize));
    }
    Vkgc::EntryHandle::ReleaseHandle(std::move(m_cacheEntry));
    m_cacheResult = elf.pCode ? Result::Success : Result::ErrorUnknown;
  }
}