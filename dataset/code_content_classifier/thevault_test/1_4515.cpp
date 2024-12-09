Module* Builder::Link(
    ArrayRef<Module*> modules)     // Array of modules indexed by shader stage, with nullptr entry
                                   //  for any stage not present in the pipeline
{
    // Add IR metadata for the shader stage to each function in each shader, and rename the entrypoint to
    // ensure there is no clash on linking.
    uint32_t metaKindId = getContext().getMDKindID(LlpcName::ShaderStageMetadata);
    for (uint32_t stage = 0; stage < ShaderStageNativeStageCount; ++stage)
    {
        Module* pModule = modules[stage];
        if (pModule == nullptr)
        {
            continue;
        }

        auto pStageMetaNode = MDNode::get(getContext(), { ConstantAsMetadata::get(getInt32(stage)) });
        for (Function& func : *pModule)
        {
            if (func.isDeclaration() == false)
            {
                func.setMetadata(metaKindId, pStageMetaNode);
                if (func.getLinkage() != GlobalValue::InternalLinkage)
                {
                    func.setName(Twine(LlpcName::EntryPointPrefix) +
                                 GetShaderStageAbbreviation(static_cast<ShaderStage>(stage), true) +
                                 "." +
                                 func.getName());
                }
            }
        }
    }

    // If there is only one shader, just change the name on its module and return it.
    Module* pPipelineModule = nullptr;
    for (auto pModule : modules)
    {
        if (pPipelineModule == nullptr)
        {
            pPipelineModule = pModule;
        }
        else if (pModule != nullptr)
        {
            pPipelineModule = nullptr;
            break;
        }
    }

    if (pPipelineModule != nullptr)
    {
        pPipelineModule->setModuleIdentifier("llpcPipeline");

        // Record pipeline state into IR metadata.
        if (m_pPipelineState != nullptr)
        {
            m_pPipelineState->RecordState(pPipelineModule);
        }
    }
    else
    {
        // Create an empty module then link each shader module into it. We record pipeline state into IR
        // metadata before the link, to avoid problems with a Constant for an immutable descriptor value
        // disappearing when modules are deleted.
        bool result = true;
        pPipelineModule = new Module("llpcPipeline", getContext());
        static_cast<Llpc::Context*>(&getContext())->SetModuleTargetMachine(pPipelineModule);
        Linker linker(*pPipelineModule);

        if (m_pPipelineState != nullptr)
        {
            m_pPipelineState->RecordState(pPipelineModule);
        }

        for (int32_t stage = 0; stage < ShaderStageNativeStageCount; ++stage)
        {
            if (modules[stage] != nullptr)
            {
                // NOTE: We use unique_ptr here. The shader module will be destroyed after it is
                // linked into pipeline module.
                if (linker.linkInModule(std::unique_ptr<Module>(modules[stage])))
                {
                    result = false;
                }
            }
        }

        if (result == false)
        {
            delete pPipelineModule;
            pPipelineModule = nullptr;
        }
    }

    return pPipelineModule;
}