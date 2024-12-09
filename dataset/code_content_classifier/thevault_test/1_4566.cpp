void Compiler::BuildShaderCacheHash(
    Context*         pContext,           // [in] Acquired context
    MetroHash::Hash* pFragmentHash,      // [out] Hash code of fragment shader
    MetroHash::Hash* pNonFragmentHash)   // [out] Hash code of all non-fragment shader
{
    MetroHash64 fragmentHasher;
    MetroHash64 nonFragmentHasher;
    auto stageMask = pContext->GetShaderStageMask();
    auto pPipelineInfo = reinterpret_cast<const GraphicsPipelineBuildInfo*>(pContext->GetPipelineBuildInfo());
    auto pPipelineOptions = pContext->GetPipelineContext()->GetPipelineOptions();

    // Build hash per shader stage
    for (auto stage = ShaderStageVertex; stage < ShaderStageGfxCount; stage = static_cast<ShaderStage>(stage + 1))
    {
        if ((stageMask & ShaderStageToMask(stage)) == 0)
        {
            continue;
        }

        auto pShaderInfo = pContext->GetPipelineShaderInfo(stage);
        auto pResUsage = pContext->GetShaderResourceUsage(stage);
        MetroHash64 hasher;

        // Update common shader info
        PipelineDumper::UpdateHashForPipelineShaderInfo(stage, pShaderInfo, true, &hasher);
        hasher.Update(pPipelineInfo->iaState.deviceIndex);

        // Update input/output usage
        PipelineDumper::UpdateHashForMap(pResUsage->inOutUsage.inputLocMap, &hasher);
        PipelineDumper::UpdateHashForMap(pResUsage->inOutUsage.outputLocMap, &hasher);
        PipelineDumper::UpdateHashForMap(pResUsage->inOutUsage.perPatchInputLocMap, &hasher);
        PipelineDumper::UpdateHashForMap(pResUsage->inOutUsage.perPatchOutputLocMap, &hasher);
        PipelineDumper::UpdateHashForMap(pResUsage->inOutUsage.builtInInputLocMap, &hasher);
        PipelineDumper::UpdateHashForMap(pResUsage->inOutUsage.builtInOutputLocMap, &hasher);
        PipelineDumper::UpdateHashForMap(pResUsage->inOutUsage.perPatchBuiltInInputLocMap, &hasher);
        PipelineDumper::UpdateHashForMap(pResUsage->inOutUsage.perPatchBuiltInOutputLocMap, &hasher);

        if (stage == ShaderStageGeometry)
        {
            // NOTE: For geometry shader, copy shader will use this special map info (from built-in outputs to
            // locations of generic outputs). We have to add it to shader hash calculation.
            PipelineDumper::UpdateHashForMap(pResUsage->inOutUsage.gs.builtInOutLocs, &hasher);
        }

        // Update vertex input state
        if (stage == ShaderStageVertex)
        {
            PipelineDumper::UpdateHashForVertexInputState(pPipelineInfo->pVertexInput, &hasher);
        }

        MetroHash::Hash  hash = {};
        hasher.Finalize(hash.bytes);

        // Add per stage hash code to fragmentHasher or nonFragmentHaser per shader stage
        auto shaderHashCode = MetroHash::Compact64(&hash);
        if (stage == ShaderStageFragment)
        {
            fragmentHasher.Update(shaderHashCode);
        }
        else
        {
            nonFragmentHasher.Update(shaderHashCode);
        }
    }

    // Add addtional pipeline state to final hasher
    if (stageMask & ShaderStageToMask(ShaderStageFragment))
    {
        // Add pipeline options to fragment hash
        fragmentHasher.Update(pPipelineOptions->includeDisassembly);
#if LLPC_CLIENT_INTERFACE_MAJOR_VERSION < 30
        fragmentHasher.Update(pPipelineOptions->autoLayoutDesc);
#endif
        fragmentHasher.Update(pPipelineOptions->scalarBlockLayout);
#if LLPC_CLIENT_INTERFACE_MAJOR_VERSION >= 28
        fragmentHasher.Update(pPipelineOptions->reconfigWorkgroupLayout);
#endif
        fragmentHasher.Update(pPipelineOptions->includeIr);
#if LLPC_CLIENT_INTERFACE_MAJOR_VERSION >= 23
        fragmentHasher.Update(pPipelineOptions->robustBufferAccess);
#endif
#if (LLPC_CLIENT_INTERFACE_MAJOR_VERSION >= 25) && (LLPC_CLIENT_INTERFACE_MAJOR_VERSION < 27)
        fragmentHasher.Update(pPipelineOptions->includeIrBinary);
#endif
        PipelineDumper::UpdateHashForFragmentState(pPipelineInfo, &fragmentHasher);
        fragmentHasher.Finalize(pFragmentHash->bytes);
    }

    if (stageMask & ~ShaderStageToMask(ShaderStageFragment))
    {
        PipelineDumper::UpdateHashForNonFragmentState(pPipelineInfo, true, &nonFragmentHasher);
        nonFragmentHasher.Finalize(pNonFragmentHash->bytes);
    }
}