ShaderCachePtr ShaderCacheManager::GetShaderCacheObject(
    const ShaderCacheCreateInfo*    pCreateInfo,    // [in] Shader cache create info
    const ShaderCacheAuxCreateInfo* pAuxCreateInfo) // [in] Shader cache auxiliary info (static fields)
{
    ShaderCachePtr pShaderCache;
    auto cacheIt = m_shaderCaches.begin();
    auto endIt = m_shaderCaches.end();

    for (; cacheIt != endIt; ++cacheIt)
    {
        if ((*cacheIt)->IsCompatible(pCreateInfo, pAuxCreateInfo))
        {
            pShaderCache = (*cacheIt);
            break;
        }
    }

    // No compatible object is found, create a new one
    if (cacheIt == endIt)
    {
        pShaderCache = std::make_shared<ShaderCache>();
        m_shaderCaches.push_back(pShaderCache);
        pShaderCache->Init(pCreateInfo, pAuxCreateInfo);
    }

    return pShaderCache;
}