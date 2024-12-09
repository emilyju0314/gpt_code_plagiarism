void Compiler::UpdateShaderCaches(
    bool                             bInsert,           // [in] To insert data or reset the shader caches
    const BinaryData*                pElfBin,           // [in] Pointer to shader data
    ShaderCache**                    ppShaderCache,     // [in] Array of shader caches; one for App's pipeline cache and one for internal cache
    CacheEntryHandle*                phEntry,           // [in] Array of handles of the shader caches entry
    uint32_t                         shaderCacheCount   // [in] Shader caches count
)
{
    for (uint32_t i = 0; i < shaderCacheCount; i++)
    {
        if (phEntry[i] != nullptr)
        {
            if (bInsert)
            {
                LLPC_ASSERT(pElfBin->codeSize > 0);
                ppShaderCache[i]->InsertShader(phEntry[i], pElfBin->pCode, pElfBin->codeSize);
            }
            else
            {
                ppShaderCache[i]->ResetShader(phEntry[i]);
            }
        }
    }
}