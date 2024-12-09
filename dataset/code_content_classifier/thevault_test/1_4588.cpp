bool PatchGroupOp::runOnModule(
    llvm::Module & module)  // [in,out] LLVM module to be run on
{
    LLVM_DEBUG(dbgs() << "Run the pass Patch-Group-Op\n");

    Patch::Init(&module);
    m_changed = false;

    // Invoke handling of "callInst" instruction
    auto pPipelineShaders = &getAnalysis<PipelineShaders>();
    for (uint32_t shaderStage = 0; shaderStage < ShaderStageCountInternal; ++shaderStage)
    {
        m_pEntryPoint = pPipelineShaders->GetEntryPoint(ShaderStage(shaderStage));
        if (m_pEntryPoint != nullptr)
        {
            m_shaderStage = ShaderStage(shaderStage);
            visit(*m_pEntryPoint);
        }
    }

    // Remove replaced "call" instructions
    for (auto pGroupCall : m_groupCalls)
    {
        pGroupCall->dropAllReferences();
        pGroupCall->eraseFromParent();
    }
    m_groupCalls.clear();

    return m_changed;
}