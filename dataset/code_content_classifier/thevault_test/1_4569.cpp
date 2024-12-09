bool PipelineShaders::runOnModule(
    Module& module)  // [in,out] LLVM module to be run on
{
    LLVM_DEBUG(dbgs() << "Run the pass Pipeline-Shaders\n");

    m_entryPointMap.clear();
    for (auto& pEntryPoint : m_entryPoints)
    {
        pEntryPoint = nullptr;
    }

    for (auto& func : module)
    {
        if ((func.empty() == false) && (func.getLinkage() != GlobalValue::InternalLinkage))
        {
            auto shaderStage = GetShaderStageFromFunction(&func);

            if (shaderStage != ShaderStageInvalid)
            {
                m_entryPoints[shaderStage] = &func;
                m_entryPointMap[&func] = shaderStage;
            }
        }
    }
    return false;
}