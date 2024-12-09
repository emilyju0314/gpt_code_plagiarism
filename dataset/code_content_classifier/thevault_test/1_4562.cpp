void Compiler::TrimSpirvDebugInfo(
    const BinaryData* pSpvBin,   // [in] SPIR-V binay code
    uint32_t          bufferSize,    // Output buffer size in bytes
    void*             pTrimSpvBin)     // [out] Trimmed SPIR-V binary code
{
    LLPC_ASSERT(bufferSize > sizeof(SpirvHeader));

    const uint32_t* pCode = reinterpret_cast<const uint32_t*>(pSpvBin->pCode);
    const uint32_t* pEnd = pCode + pSpvBin->codeSize / sizeof(uint32_t);
    const uint32_t* pCodePos = pCode + sizeof(SpirvHeader) / sizeof(uint32_t);

    uint32_t* pTrimEnd = reinterpret_cast<uint32_t*>(VoidPtrInc(pTrimSpvBin, bufferSize));
    LLPC_UNUSED(pTrimEnd);
    uint32_t* pTrimCodePos = reinterpret_cast<uint32_t*>(VoidPtrInc(pTrimSpvBin, sizeof(SpirvHeader)));

    // Copy SPIR-V header
    memcpy(pTrimSpvBin, pCode, sizeof(SpirvHeader));

    // Copy SPIR-V instructions
    while (pCodePos < pEnd)
    {
        uint32_t opCode = (pCodePos[0] & OpCodeMask);
        uint32_t wordCount = (pCodePos[0] >> WordCountShift);
        switch (opCode)
        {
        case spv::OpString:
        case spv::OpSource:
        case spv::OpSourceContinued:
        case spv::OpSourceExtension:
        case spv::OpName:
        case spv::OpMemberName:
        case spv::OpLine:
        case spv::OpNop:
        case spv::OpNoLine:
        case spv::OpModuleProcessed:
            {
                // Skip debug instructions
                break;
            }
        default:
            {
                // Copy other instructions
                LLPC_ASSERT(pCodePos + wordCount <= pEnd);
                LLPC_ASSERT(pTrimCodePos + wordCount <= pTrimEnd);
                memcpy(pTrimCodePos, pCodePos, wordCount * sizeof(uint32_t));
                pTrimCodePos += wordCount;
                break;
            }
        }

        pCodePos += wordCount;
    }

    LLPC_ASSERT(pTrimCodePos == pTrimEnd);
}