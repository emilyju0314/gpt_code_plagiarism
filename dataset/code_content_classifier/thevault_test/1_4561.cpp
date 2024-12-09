Result Compiler::CollectInfoFromSpirvBinary(
    const BinaryData*                pSpvBinCode,           // [in] SPIR-V binary data
    ShaderModuleInfo*                pShaderModuleInfo,     // [out] Shader module information
    SmallVector<ShaderEntryName, 4>& shaderEntryNames       // [out] Entry names for this shader module
    )
{
    Result result = Result::Success;

    const uint32_t* pCode = reinterpret_cast<const uint32_t*>(pSpvBinCode->pCode);
    const uint32_t* pEnd = pCode + pSpvBinCode->codeSize / sizeof(uint32_t);

    const uint32_t* pCodePos = pCode + sizeof(SpirvHeader) / sizeof(uint32_t);

    // Parse SPIR-V instructions
    std::unordered_set<uint32_t> capabilities;

    while (pCodePos < pEnd)
    {
        uint32_t opCode = (pCodePos[0] & OpCodeMask);
        uint32_t wordCount = (pCodePos[0] >> WordCountShift);

        if ((wordCount == 0) || (pCodePos + wordCount > pEnd))
        {
            LLPC_ERRS("Invalid SPIR-V binary\n");
            result = Result::ErrorInvalidShader;
            break;
        }

        // Parse each instruction and find those we are interested in
        switch (opCode)
        {
        case spv::OpCapability:
            {
                LLPC_ASSERT(wordCount == 2);
                auto capability = static_cast<spv::Capability>(pCodePos[1]);
                capabilities.insert(capability);
                break;
            }
        case spv::OpExtension:
            {
                if ((strncmp(reinterpret_cast<const char*>(&pCodePos[1]), "SPV_AMD_shader_ballot",
                    strlen("SPV_AMD_shader_ballot")) == 0) && (pShaderModuleInfo->useSubgroupSize == false))
                {
                    pShaderModuleInfo->useSubgroupSize = true;
                }
                break;
            }
        case spv::OpDPdx:
        case spv::OpDPdy:
        case spv::OpDPdxCoarse:
        case spv::OpDPdyCoarse:
        case spv::OpDPdxFine:
        case spv::OpDPdyFine:
        case spv::OpImageSampleImplicitLod:
        case spv::OpImageSampleDrefImplicitLod:
        case spv::OpImageSampleProjImplicitLod:
        case spv::OpImageSampleProjDrefImplicitLod:
        case spv::OpImageSparseSampleImplicitLod:
        case spv::OpImageSparseSampleProjDrefImplicitLod:
        case spv::OpImageSparseSampleProjImplicitLod:
            {
                pShaderModuleInfo->useHelpInvocation = true;
                break;
            }
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
                pShaderModuleInfo->debugInfoSize += wordCount * sizeof(uint32_t);
                break;
            }
        case OpSpecConstantTrue:
        case OpSpecConstantFalse:
        case OpSpecConstant:
        case OpSpecConstantComposite:
        case OpSpecConstantOp:
            {
                pShaderModuleInfo->useSpecConstant = true;
                break;
            }
        case OpEntryPoint:
            {
                ShaderEntryName entry = {};
                // The fourth word is start of the name string of the entry-point
                entry.pName = reinterpret_cast<const char*>(&pCodePos[3]);
                entry.stage = static_cast<ShaderStage>(pCodePos[1]);
                shaderEntryNames.push_back(entry);
                break;
            }
        default:
            {
                break;
            }
        }
        pCodePos += wordCount;
    }

    if (capabilities.find(spv::CapabilityVariablePointersStorageBuffer) != capabilities.end())
    {
        pShaderModuleInfo->enableVarPtrStorageBuf = true;
    }

    if (capabilities.find(spv::CapabilityVariablePointers) != capabilities.end())
    {
        pShaderModuleInfo->enableVarPtr = true;
    }

    if ((pShaderModuleInfo->useSubgroupSize == false) &&
        ((capabilities.find(spv::CapabilityGroupNonUniform) != capabilities.end()) ||
        (capabilities.find(spv::CapabilityGroupNonUniformVote) != capabilities.end()) ||
        (capabilities.find(spv::CapabilityGroupNonUniformArithmetic) != capabilities.end()) ||
        (capabilities.find(spv::CapabilityGroupNonUniformBallot) != capabilities.end()) ||
        (capabilities.find(spv::CapabilityGroupNonUniformShuffle) != capabilities.end()) ||
        (capabilities.find(spv::CapabilityGroupNonUniformShuffleRelative) != capabilities.end()) ||
        (capabilities.find(spv::CapabilityGroupNonUniformClustered) != capabilities.end()) ||
        (capabilities.find(spv::CapabilityGroupNonUniformQuad) != capabilities.end()) ||
        (capabilities.find(spv::CapabilitySubgroupBallotKHR) != capabilities.end()) ||
        (capabilities.find(spv::CapabilitySubgroupVoteKHR) != capabilities.end()) ||
        (capabilities.find(spv::CapabilityGroups) != capabilities.end())))
    {
        pShaderModuleInfo->useSubgroupSize = true;
    }

    return result;
}