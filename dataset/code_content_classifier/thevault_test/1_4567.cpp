bool SpirvLowerResourceCollect::runOnModule(
    Module& module)  // [in,out] LLVM module to be run on
{
    LLVM_DEBUG(dbgs() << "Run the pass Spirv-Lower-Resource-Collect\n");

    SpirvLower::Init(&module);

    m_pResUsage = m_pContext->GetShaderResourceUsage(m_shaderStage);

    CollectExecutionModeUsage();

    // Collect unused globals and remove them
    std::unordered_set<GlobalVariable*> removedGlobals;
    for (auto pGlobal = m_pModule->global_begin(), pEnd = m_pModule->global_end(); pGlobal != pEnd; ++pGlobal)
    {
        if (pGlobal->user_empty())
        {
            Value* pInitializer = nullptr;
            if (pGlobal->hasInitializer())
            {
                pInitializer = pGlobal->getInitializer();
            }

            if ((pInitializer == nullptr) || isa<UndefValue>(pInitializer))
            {
                removedGlobals.insert(&*pGlobal);
            }
        }
    }

    for (auto pGlobal : removedGlobals)
    {
        pGlobal->dropAllReferences();
        pGlobal->eraseFromParent();
    }

    bool useViewIndex = false;
    bool useImages = false;

    // Collect resource usages from globals
    for (auto pGlobal = m_pModule->global_begin(), pEnd = m_pModule->global_end(); pGlobal != pEnd; ++pGlobal)
    {
        const Type* pGlobalTy = pGlobal->getType()->getContainedType(0);

        auto addrSpace = pGlobal->getType()->getAddressSpace();
        switch (addrSpace)
        {
        case SPIRAS_Constant:
            {
                if (pGlobal->hasMetadata(gSPIRVMD::PushConst))
                {
                    // Push constant
                    MDNode* pMetaNode = pGlobal->getMetadata(gSPIRVMD::PushConst);
                    auto pushConstSize = mdconst::dyn_extract<ConstantInt>(pMetaNode->getOperand(0))->getZExtValue();
                    m_pResUsage->pushConstSizeInBytes = pushConstSize;
                }
                else
                {
                    useImages = true;

                    // TODO: Will support separated texture resource/sampler.
                    DescriptorType descType = DescriptorType::Texture;

                    // NOTE: For texture buffer and image buffer, the descriptor type should be set to "TexelBuffer".
                    if (pGlobalTy->isPointerTy())
                    {
                        Type* pImageType = pGlobalTy->getPointerElementType();
                        std::string imageTypeName = pImageType->getStructName();
                        // Format of image opaque type: ...[.SampledImage.<date type><dim>]...
                        if (imageTypeName.find(".SampledImage") != std::string::npos)
                        {
                            auto pos = imageTypeName.find("_");
                            LLPC_ASSERT(pos != std::string::npos);

                            ++pos;
                            Dim dim = static_cast<Dim>(imageTypeName[pos] - '0');
                            if (dim == DimBuffer)
                            {
                                descType = DescriptorType::TexelBuffer;
                            }
                            else if (dim == DimSubpassData)
                            {
                                LLPC_ASSERT(m_shaderStage == ShaderStageFragment);
                                m_pResUsage->builtInUsage.fs.fragCoord = true;
                                useViewIndex = true;
                            }
                        }
                    }
                }
                break;
            }
        case SPIRAS_Private:
        case SPIRAS_Global:
        case SPIRAS_Local:
        case SPIRAS_Input:
        case SPIRAS_Output:
            {
                break;
            }
        case SPIRAS_Uniform:
            {
                // Buffer block
#ifndef NDEBUG
                MDNode* pMetaNode = pGlobal->getMetadata(gSPIRVMD::Resource);
                auto blockType = mdconst::dyn_extract<ConstantInt>(pMetaNode->getOperand(2))->getZExtValue();
                LLPC_ASSERT((blockType == BlockTypeUniform) || (blockType == BlockTypeShaderStorage));
#endif
                break;
            }
        default:
            {
                LLPC_NEVER_CALLED();
                break;
            }
        }
    }

    if (m_shaderStage == ShaderStageCompute)
    {
        auto& builtInUsage = m_pResUsage->builtInUsage.cs;

        bool reconfig = false;

        switch (static_cast<WorkgroupLayout>(builtInUsage.workgroupLayout))
        {
        case WorkgroupLayout::Unknown:
#if LLPC_CLIENT_INTERFACE_MAJOR_VERSION >= 28
            // If no configuration has been specified, apply a reconfigure if the compute shader uses images and the
            // pipeline option was enabled.
            reconfig = useImages && m_pContext->GetTargetMachinePipelineOptions()->reconfigWorkgroupLayout;
#endif
            break;
        case WorkgroupLayout::Linear:
            // The hardware by default applies the linear rules, so just ban reconfigure and we're done.
            reconfig = false;
            break;
        case WorkgroupLayout::Quads:
            // 2x2 requested.
            reconfig = true;
            break;
        case WorkgroupLayout::SexagintiQuads:
            // 8x8 requested.
            reconfig = true;
            break;
        }

        if (reconfig)
        {
            if (((builtInUsage.workgroupSizeX % 2) == 0) && ((builtInUsage.workgroupSizeY % 2) == 0))
            {
                if (((builtInUsage.workgroupSizeX > 8) && (builtInUsage.workgroupSizeY >= 8)) ||
                    ((builtInUsage.workgroupSizeX >= 8) && (builtInUsage.workgroupSizeY > 8)))
                {
                    // If our local size in the X & Y dimensions are greater than 8, we can reconfigure.
                    builtInUsage.workgroupLayout = static_cast<uint32_t>(WorkgroupLayout::SexagintiQuads);
                }
                else
                {
                    // If our local size in the X & Y dimensions are multiples of 2, we can reconfigure.
                    builtInUsage.workgroupLayout = static_cast<uint32_t>(WorkgroupLayout::Quads);
                }
            }
        }
    }

    return true;
}