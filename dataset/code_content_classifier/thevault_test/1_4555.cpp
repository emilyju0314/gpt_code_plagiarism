void Compiler::TranslateSpirvToLlvm(
    const PipelineShaderInfo*   pShaderInfo, // [in] Specialization info
    Module*                     pModule)             // [in/out] Module to translate into, initially empty
{
    BinaryData  optSpirvBin = {};
    const ShaderModuleData* pModuleData = reinterpret_cast<const ShaderModuleData*>(pShaderInfo->pModuleData);
    LLPC_ASSERT(pModuleData->binType == BinaryType::Spirv);
    const BinaryData* pSpirvBin = &pModuleData->binCode;
    if (OptimizeSpirv(pSpirvBin, &optSpirvBin) == Result::Success)
    {
        pSpirvBin = &optSpirvBin;
    }

    std::string spirvCode(static_cast<const char*>(pSpirvBin->pCode), pSpirvBin->codeSize);
    std::istringstream spirvStream(spirvCode);
    std::string errMsg;
    SPIRVSpecConstMap specConstMap;

    // Build specialization constant map
    if (pShaderInfo->pSpecializationInfo != nullptr)
    {
        for (uint32_t i = 0; i < pShaderInfo->pSpecializationInfo->mapEntryCount; ++i)
        {
            SPIRVSpecConstEntry specConstEntry  = {};
            auto pMapEntry = &pShaderInfo->pSpecializationInfo->pMapEntries[i];
            specConstEntry.DataSize= pMapEntry->size;
            specConstEntry.Data = VoidPtrInc(pShaderInfo->pSpecializationInfo->pData, pMapEntry->offset);
            specConstMap[pMapEntry->constantID] = specConstEntry;
        }
    }

    Context* pContext = static_cast<Context*>(&pModule->getContext());

    if (readSpirv(pContext->GetBuilder(),
                  pShaderInfo->pModuleData,
                  spirvStream,
                  static_cast<spv::ExecutionModel>(pShaderInfo->entryStage),
                  pShaderInfo->pEntryTarget,
                  specConstMap,
                  pModule,
                  errMsg) == false)
    {
        report_fatal_error(Twine("Failed to translate SPIR-V to LLVM (") +
                            GetShaderStageName(static_cast<ShaderStage>(pShaderInfo->entryStage)) + " shader): " + errMsg,
                           false);
    }

    CleanOptimizedSpirv(&optSpirvBin);

    // NOTE: Our shader entrypoint is marked in the SPIR-V reader as dllexport. Here we mark it as follows:
    //   * remove the dllexport;
    //   * ensure it is public.
    // Also mark all other functions internal and always_inline.
    //
    // TODO: We should rationalize this code as follows:
    //   1. Add code to the spir-v reader to add the entrypoint name as metadata;
    //   2. change this code here to detect that, instead of DLLExport;
    //   3. remove the code we added to the spir-v reader to detect the required entrypoint and mark it as DLLExport;
    //   4. remove the required entrypoint name and execution model args that we added to the spir-v reader API, to
    //      make it closer to the upstream Khronos copy of that code.
    for (auto& func : *pModule)
    {
        if (func.empty())
        {
            continue;
        }
        if (func.getDLLStorageClass() == GlobalValue::DLLExportStorageClass)
        {
            func.setDLLStorageClass(GlobalValue::DefaultStorageClass);
            func.setLinkage(GlobalValue::ExternalLinkage);
        }
        else
        {
            func.setLinkage(GlobalValue::InternalLinkage);
            func.addFnAttr(Attribute::AlwaysInline);
        }
    }
}