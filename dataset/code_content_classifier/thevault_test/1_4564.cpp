ShaderEntryState Compiler::LookUpShaderCaches(
    IShaderCache*                    pAppPipelineCache, // [in]    App's pipeline cache
    MetroHash::Hash*                 pCacheHash,        // [in]    Hash code of the shader
    BinaryData*                      pElfBin,           // [inout] Pointer to shader data
    ShaderCache**                    ppShaderCache,     // [in]    Array of shader caches.
    CacheEntryHandle*                phEntry            // [in]    Array of handles of the shader caches entry
    )
{
    ShaderEntryState cacheEntryState  = ShaderEntryState::New;
    uint32_t         shaderCacheCount = 1;
    Result           result           = Result::Success;

    if (pAppPipelineCache != nullptr)
    {
        ppShaderCache[0] = static_cast<ShaderCache*>(pAppPipelineCache);
        ppShaderCache[1] = m_shaderCache.get();
        shaderCacheCount = 2;
    }
    else
    {
        ppShaderCache[0] = m_shaderCache.get();
        ppShaderCache[1] = nullptr;
    }

    if (cl::ShaderCacheMode == ShaderCacheForceInternalCacheOnDisk)
    {
        ppShaderCache[0] = m_shaderCache.get();
        ppShaderCache[1] = nullptr;
        shaderCacheCount = 1;
    }

    for (uint32_t i = 0; i < shaderCacheCount; i++)
    {
        cacheEntryState = ppShaderCache[i]->FindShader(*pCacheHash, true, &phEntry[i]);
        if (cacheEntryState == ShaderEntryState::Ready)
        {
            result = ppShaderCache[i]->RetrieveShader(phEntry[i], &pElfBin->pCode, &pElfBin->codeSize);
            // Re-try if shader cache return error unknown
            if (result == Result::ErrorUnknown)
            {
                result = Result::Success;
                phEntry[i] = nullptr;
                cacheEntryState = ShaderEntryState::Compiling;
            }
            else
            {
                if (i == 1)
                {
                    // App's pipeline cache misses while internal cache hits
                    if (phEntry[0] != nullptr)
                    {
                        LLPC_ASSERT(pElfBin->codeSize > 0);
                        ppShaderCache[0]->InsertShader(phEntry[0], pElfBin->pCode, pElfBin->codeSize);
                    }
                }
                break;
            }
        }
    }

    return cacheEntryState;
}